import math

x = int(input("Indique um número: "))
fat = 1

for i in range(x, 0, -1):
    fat = math.factorial(x)
print(fat)