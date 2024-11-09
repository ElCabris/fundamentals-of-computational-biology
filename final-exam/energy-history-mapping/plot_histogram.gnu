# Configuración de la terminal y el archivo de salida
set terminal png size 800,600
set output 'energy_histogram.png'

# Títulos y etiquetas
set title "Histograma de Energía Total"
set xlabel "Energía Total"
set ylabel "Frecuencia"

# Configuración para estilo de histograma
set style data histograms
set style histogram cluster gap 1
set style fill solid 0.5 border -1

# Mostrar cada valor de energía como etiqueta en el eje x
set xtic rotate by -45 scale 0   # Rotar etiquetas de x para que no se superpongan

# Graficar el archivo de datos con histogramas
plot "energy_histogram.dat" using 2:xtic(1) title "Frecuencia de Energías" linecolor rgb "blue"

