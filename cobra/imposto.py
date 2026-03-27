valor = float(input("Digite um valor: "))
estado = input("Selecione um estado: ").upper()

if estado == "MG":
    imposto = 0.07
    print(f"Valor total (Minas Gerais): R${valor + (valor * imposto)}")
elif estado == "SP":
    imposto = 0.12
    print(f"Valor total (São Paulo): R$", valor + (valor * imposto))
elif estado == "RJ":
    imposto = 0.15
    print(f"Valor total (Rio de Janeiro): R$", valor + (valor * imposto))
elif estado == "MS":
    imposto = 0.08
    print(f"Valor total (Mato Grosso do Sul): R$", valor + (valor * imposto))
else:
    print("❌ Erro! Estado inválido")