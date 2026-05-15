# Peça ao usuário um número inteiro e mostre a tabuada usando for.

numero = int(input("Digite um número para ver a tabela: "))

print("=" * 15)
for i in range(1, 11):
    print(f"{numero} x {i:2} = {numero * i}")

print("=" * 15)