# Faça um programa que peça 10 números usando for e informe:
#   - quantos números são positivos;
#   - quantos números são negativos;
#   - quantos números são múltiplos de 3.

positivos = 0
negativos = 0
tres = 0

for i in range(1, 11):
    numeros = int(input(f"Digite o {i}º número: "))

    if numeros > 0:
        positivos += 1        
    
    if numeros < 0:
        negativos += 1

    if numeros % 3 == 0:
        tres += 1        

print(f"Números positivos: {positivos}")
print(f"Números negativos: {negativos}")
print(f"Números múltiplos de 3: {tres}")