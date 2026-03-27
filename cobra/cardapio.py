print("==== MENU ====")
codigo = int(input("Código: "))
quantidade = int(input("Quantidade: "))

if codigo == 100:
    cachorro_quente = 1.20
    print("CACHORRO QUENTE")
    print(f"Total: R${cachorro_quente * quantidade:.2f}")
elif codigo == 101:
    bauru_simples = 1.30
    print("BAURU")
    print(f"Total: R${bauru_simples * quantidade:.2f}")
elif codigo == 102:
    bauru_com_ovo = 1.50
    print("BAURU COM OVO")
    print(f"Total: R${bauru_com_ovo * quantidade:.2f}")
elif codigo == 103:
    hamburguer = 1.20
    print("HAMBURGUER")
    print(f"Total: R${hamburguer * quantidade:.2f}")
elif codigo == 104:
    cheeseburguer = 1.70
    print("CHEESEBURGUER")
    print(f"Total: R${cheeseburguer * quantidade:.2f}")
elif codigo == 105:
    suco = 2.20
    print("SUCO")
    print(f"Total: {suco * quantidade:.2f}")