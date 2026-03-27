idade = int(input("Digite a sua idade: "))
tempo_servico = int(input("Digite o seu tempo de serviço: "))

if idade >= 65 or tempo_servico == 30:
    print("Você pode se aposentar.")
elif idade >= 60 and tempo_servico >= 25:
    print("Você pode se aposentar atendendo às esses requisitos.")
else:
    print("Você ainda não pode se aposentar.")