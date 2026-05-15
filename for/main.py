soma = 0
n = int(input("Informe a quantidade de números a somar: "))

# for: faz a iteração entre o início e fim da variável. 
for i in range(1, n + 1):
    numero = int(input(f"Digite o {i}º número: "))
    soma += numero
print(f"Total: {soma}")