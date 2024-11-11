import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('results.csv')

last_column = df.iloc[:, -1]

plt.figure(figsize=(10, 6))  # Tamaño opcional del gráfico
plt.hist(last_column, bins=20, color='skyblue', edgecolor='black') 
plt.xlabel('Distancias')
plt.ylabel('Frecuencia')
plt.title('Histograma de Distancias')

plt.savefig("histograma_distances.jpg", format="jpg")

