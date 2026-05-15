# Peça dois números inteiros ao usuário para determinar um intervalo:
#   - O primeiro número será o inicial do intervalo;
#   - O segundo número será o final do intervalo.
# Use para calcular a soma de todos os números pares dentro desse intervalo.

inicio = int(input("Digite o início do intervalo: "))
final = int(input("Indique o fim do intervalo: "))
soma = 0

for n in range(inicio, final + 1): # n = numero
    if n % 2 == 0: # Verifica se o número é par
        soma += n

print(f"Soma total: {soma}") # Total