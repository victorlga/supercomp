import random


def gerar_arquivos():
    for i in range(10):
        tamanho_conjunto = [3, 10, 20]
        len_tamanhos = len(tamanho_conjunto)
        conjunto_numeros = [random.randint(1, tamanho_conjunto[i%len_tamanhos] * 10) for _ in range(tamanho_conjunto[i%len_tamanhos])]

        target = random.randint(tamanho_conjunto[i%len_tamanhos] * 10, tamanho_conjunto[i%len_tamanhos] * 50)

        with open(f'data/input_{i}.txt', 'w') as arquivo:
            arquivo.write(f"{target}\n")
            arquivo.writelines([f"{numero}\n" for numero in conjunto_numeros])

# Chamando a função para gerar os arquivos
gerar_arquivos()
