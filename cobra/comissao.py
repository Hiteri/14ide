print("=== VENDA MENSAL + COMISSÃO AO VENDEDOR ===")

venda_mensal = float(input("Digite o valor da venda: "))

if venda_mensal >= 100000.00:
    comissao = 700.00 + (venda_mensal * 0.16)
    print(f"Comissão acima de R$100.000,00: R${comissao:.2f}")
elif venda_mensal < 100000.00 and venda_mensal >= 80000.00:
    comissao = 650.00 + (venda_mensal  * 0.14)
    print(f"Comissão acima de R$80.000,00: R${comissao:.2f}")
elif venda_mensal < 80000.00 and venda_mensal >= 60000.00:
    comissao = 600.00 + (venda_mensal * 0.14)
    print(f"Comissão acima de R$60.000,00: R${comissao:.2f}")
elif venda_mensal < 60000.00 and venda_mensal >= 40000.00:
    comissao = 550.00 + (venda_mensal * 0.14)
    print(f"Comissão acima de R$40.000,00: R${comissao:.2f}")
elif venda_mensal < 40000.00 and venda_mensal >= 20000.00:
    comissao = 500.00 + (venda_mensal * 0.14)
    print(f"Comissão acima de R$20.000,00: R${comissao:.2f}")
elif venda_mensal < 20000.00:
    comissao = 400.00 + (venda_mensal * 0.14)
    print(f"Comissão abaixo de R$20.000: R${comissao:.2f}")
else:
    print("Erro! Valor mensal inválido ❌")