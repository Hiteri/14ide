print("=== Consumo de Gasolina do Carro ===")

quilometro = int(input("Digite a sua distância: "))
litros = int(input("Digite quantos litros foram consumidos: "))
km_por_l = quilometro / litros

print(f"Distância percorrida: {km_por_l:.2f}km/l")
if km_por_l < 8:
    print("Venda o carro")
elif 8 <= km_por_l <= 12:
    print("Econômico!")
elif km_por_l > 12:
    print("Super econômico!")