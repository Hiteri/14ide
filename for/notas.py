# Faça um programa que peça 5 notas ao usuário usando for e depois calcule a média.
soma = 0

for i in range(1, 6):
    notas = float(input(f"Digite a {i}ª nota: "))
    soma += notas

media = soma / i
print(f"Média: {media:.2f}")