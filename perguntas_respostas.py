import streamlit as st
import sqlite3
import hashlib
from datetime import datetime

# ---------------------------
# Funções de segurança
# ---------------------------
def hash_senha(senha: str) -> str:
    return hashlib.sha256(senha.encode()).hexdigest()

# ---------------------------
# Banco de dados
# ---------------------------
def criar_tabelas():
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS usuarios (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            email TEXT UNIQUE NOT NULL,
            senha TEXT NOT NULL
        )
    """)

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS perguntas (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            usuario TEXT NOT NULL,
            pergunta TEXT NOT NULL,
            data TEXT NOT NULL
        )
    """)

    cursor.execute("""
        CREATE TABLE IF NOT EXISTS respostas (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            pergunta_id INTEGER NOT NULL,
            usuario TEXT NOT NULL,
            resposta TEXT NOT NULL,
            data TEXT NOT NULL,
            FOREIGN KEY (pergunta_id) REFERENCES perguntas(id)
        )
    """)

    conn.commit()
    conn.close()

def inserir_usuario(username, email, senha):
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()
    try:
        senha_hash = hash_senha(senha)
        cursor.execute("INSERT INTO usuarios (username, email, senha) VALUES (?, ?, ?)", 
                       (username, email, senha_hash))
        conn.commit()
        return True
    except sqlite3.IntegrityError:
        return False
    finally:
        conn.close()

def autenticar(email, senha):
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()
    senha_hash = hash_senha(senha)
    cursor.execute("SELECT * FROM usuarios WHERE email=? AND senha=?", (email, senha_hash))
    usuario = cursor.fetchone()
    conn.close()
    return usuario

def adicionar_pergunta(usuario, pergunta):
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO perguntas (usuario, pergunta, data) VALUES (?, ?, ?)", 
                   (usuario, pergunta, datetime.now().strftime("%d-%m-%Y %H:%M")))
    conn.commit()
    conn.close()

def listar_perguntas():
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM perguntas ORDER BY id DESC")
    perguntas = cursor.fetchall()
    conn.close()
    return perguntas

def adicionar_resposta(pergunta_id, usuario, resposta):
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO respostas (pergunta_id, usuario, resposta, data) VALUES (?, ?, ?, ?)", 
                   (pergunta_id, usuario, resposta, datetime.now().strftime("%d/%m/%Y %H:%M")))
    conn.commit()
    conn.close()

def listar_respostas(pergunta_id):
    conn = sqlite3.connect("usuarios.db")
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM respostas WHERE pergunta_id=? ORDER BY id ASC", (pergunta_id,))
    respostas = cursor.fetchall()
    conn.close()
    return respostas

# ---------------------------
# Inicialização
# ---------------------------
criar_tabelas()

if "page" not in st.session_state:
    st.session_state.page = "cadastro"
if "usuario_logado" not in st.session_state:
    st.session_state.usuario_logado = None

def mudar_pagina(pagina):
    st.session_state.page = pagina
    st.rerun()  # atualizado!

# ---------------------------
# Função de cabeçalho
# ---------------------------
def header():
    st.markdown("<div style>='text-align: center;'>", unsafe_allow_html=True)
    st.image("KnowledgePulse.png", width=300)
    st.markdown("</div><hr>", unsafe_allow_html=True)
    
# ---------------------------
# Páginas
# ---------------------------
def cadastro():
    header()
    st.title("Cadastro")

    username = st.text_input("Nome", key="cadastro_usuario")
    email = st.text_input("Email", key="cadastro_email")
    senha = st.text_input("Senha", type="password", key="cadastro_senha")
    confirmar = st.text_input("Confirmar Senha", type="password", key="cadastro_confirmar")

    if st.button("Cadastrar"):
        if not username or not email or not senha or not confirmar:
            st.warning("Preencha todos os campos.")
        elif senha != confirmar:
            st.error("As senhas não coincidem!")
        else:
            if inserir_usuario(username, email, senha):
                st.success("Cadastro realizado com sucesso!")
                mudar_pagina("login")
            else:
                st.error("Nome ou email já cadastrados!")

def login():
    header()
    st.title("Login")

    email = st.text_input("Email", key="login_email")
    senha = st.text_input("Senha", type="password", key="login_senha")

    if st.button("Entrar"):
        usuario = autenticar(email, senha)
        if usuario:
            st.session_state.usuario_logado = usuario[1]  # salva username
            mudar_pagina("qna")
        else:
            st.error("Email ou senha inválidos.")

    if st.button("Não tem conta? Cadastre-se"):
        st.session_state.pop("login_email", None)
        st.session_state.pop("login_senha", None)
        mudar_pagina("cadastro")

def qna():
    header()
    st.title(f"Fórum dos Colaboradores 💭")
    st.write(f"Usuário logado: **{st.session_state.usuario_logado}**")

    # Criar nova pergunta
    st.subheader("Fazer uma pergunta")
    nova_pergunta = st.text_area("Digite sua pergunta:")
    if st.button("Enviar Pergunta"):
        if nova_pergunta.strip():
            adicionar_pergunta(st.session_state.usuario_logado, nova_pergunta)
            st.success("Pergunta enviada!")
            st.rerun()

    # Listar perguntas
    st.subheader("Perguntas existentes")
    perguntas = listar_perguntas()
    if perguntas:
        for p in perguntas:
            st.markdown(f"**{p[1]}** perguntou em {p[3]}:")
            st.info(p[2])

            # Respostas
            respostas = listar_respostas(p[0])
            if respostas:
                for r in respostas:
                    st.write(f"↳ {r[1]} respondeu em {r[4]}:")
                    st.success(r[3])

            # Responder
            resposta_texto = st.text_input("Sua resposta:", key=f"resp_{p[0]}")
            if st.button("Responder", key=f"btn_resp_{p[0]}"):
                if resposta_texto.strip():
                    adicionar_resposta(p[0], st.session_state.usuario_logado, resposta_texto)
                    st.rerun()
            st.markdown("---")
    else:
        st.write("Nenhuma pergunta cadastrada ainda.")

    if st.button("Sair"):
        st.session_state.usuario_logado = None
        mudar_pagina("login")

# ---------------------------
# Controle de navegação
# ---------------------------
if st.session_state.page == "cadastro":
    cadastro()
elif st.session_state.page == "login":
    login()
elif st.session_state.page == "qna":
    qna()
