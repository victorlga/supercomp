import subprocess
import time
import matplotlib.pyplot as plt

tamanhos = range(3, 301)
tempos_q4 = []
tempos_q4_m = []

for tamanho in tamanhos:
    start_time = time.time()
    subprocess.run(['./q4', str(tamanho)])
    tempos_q4.append(time.time() - start_time)

    start_time = time.time()
    subprocess.run(['./q4_m', str(tamanho)])
    tempos_q4_m.append(time.time() - start_time)

plt.figure(figsize=(10, 6))
plt.plot(tamanhos, tempos_q4, label='q4', marker='o')
plt.plot(tamanhos, tempos_q4_m, label='q4_m', marker='x')
plt.xlabel('Tamanho da Matriz')
plt.ylabel('Tempo de Execução (s)')
plt.title('Tempo de Execução por Tamanho da Matriz')
plt.legend()
plt.grid(True)
plt.show()
