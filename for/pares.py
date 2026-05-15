# Faça um programa que mostre todos os números pares entre 1 e 50 utilizando for.

print("Números pares entre 1 e 50:")
for i in range(1, 51):
    if i % 2 == 0:
        print(i, end=" ")