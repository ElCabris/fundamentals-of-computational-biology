import pandas as pd
import matplotlib.pyplot as plt

# Cargar el archivo CSV
df = pd.read_csv("results.csv")

# Filtrar las filas donde la primera columna termina con '01'
filtered_df = df[df.iloc[:, 0].astype(str).str.endswith('01')]

# Contar cuántas veces aparece cada elemento en la primera columna filtrada
frecuencias = filtered_df.iloc[:, 0].value_counts()

# Contar cuántos elementos tienen cada número específico de apariciones
apariciones = frecuencias.value_counts()

# Graficar el histograma
plt.figure(figsize=(8, 6))
apariciones.sort_index().plot(kind='bar', color='skyblue')
plt.title('Número de elementos con un número específico de apariciones')
plt.xlabel('Número de apariciones')
plt.ylabel('Número de elementos')

# Guardar el histograma en un archivo .jpg
plt.savefig('histograma_apariciones_especificas_01.jpg', format='jpg')
