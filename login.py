import tkinter as tk

contas = [
    ("Hide", "123"),
    ("Denji", "cachorro")
]

janela = tk.Tk()
janela.title("Login")
janela.geometry("400x300")

pagina_login = tk.Frame(janela)
pagina_login.pack()

tk.Label(pagina_login, text="Usuário").pack()
usuario_entrada = tk.Entry(pagina_login)
usuario_entrada.pack()

tk.Label(pagina_login, text="Senha").pack()
senha_entry = tk.Entry(pagina_login)
senha_entry.pack()

def login():
    usuario = usuario_entrada.get()
    senha = senha_entry.get()
    if (usuario, senha) in contas:
        pagina_login.pack_forget()
        pagina_sistema.pack()
    else:
        mensagem_label['text'] = "As credenciais são inválidas!"

tk.Button(pagina_login, text="Login", command=login).pack()

mensagem_label = tk.Label(pagina_login, text="")
mensagem_label.pack()

pagina_sistema = tk.Frame()
tk.Label(pagina_sistema, text="Bem vindo ao Sistema!").pack()

janela.mainloop()