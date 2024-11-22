import matplotlib.pyplot as plt
from collections import Counter

# Nombre del archivo
filename = "results.txt"

# Contador para las palabras
word_counts = Counter()

try:
    with open(filename, "r") as file:
        for line in file:
            line = line.strip()  # Eliminar espacios al principio y final
            if line and line[0].isalpha():  # Verificar si la línea inicia con una letra
                first_word = line.split()[0]  # Obtener la primera palabra
                word_counts[first_word] += 1  # Incrementar el contador
except FileNotFoundError:
    print(f"El archivo '{filename}' no fue encontrado.")
    exit()

# Crear el histograma
labels, values = zip(*word_counts.items())  # Separar palabras y frecuencias

plt.figure(figsize=(10, 6))
plt.bar(labels, values, color="skyblue", edgecolor="black")
plt.xlabel("Palabras")
plt.ylabel("Frecuencia")
plt.title("Frecuencia de las primeras palabras que inician con una letra")
plt.xticks(rotation=45, ha="right")  # Rotar etiquetas para mayor legibilidad
plt.tight_layout()

# Mostrar el histograma
plt.show()

