function play(){
    //alert("Funcionou Parça...");
    /* alert - Caixa de mensagem
       let - variável genérica
       Math - Objeto matemática floor (arredonda para baixo)
                                random (número aleatório)
       document - Objeto página HTML (documento)
       getElementById (resgatar a tag pelo id)
       innerText (altera o texto durante a execução da página) 
    */

    let maquina = Math.floor((Math.random() * 101)); // Escolhe um número aleatório entre 1 a 100 (0-101)
    document.getElementById("numeroMaquina").innerText = maquina;
    let usuario = Math.floor((Math.random() * 101)); // Escolhe um número aleatório entre 1 a 100 (0-101)
    document.getElementById("meuNumero").innerText = usuario;

    let mensagem = "";    
    if(usuario > maquina){
        mensagem = "YOU WIN! 🥳";
    }
    else if(usuario < maquina){
        mensagem = "YOU LOSE! 😭";
    }
    else{
        mensagem = "TIE! 😐"
    }
    document.getElementById("resultado").innerText = mensagem;
}