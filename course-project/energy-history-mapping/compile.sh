#!/bin/bash
echo "compilando programa"
g++ history_mapping.cpp -o get_energies
echo "compilación completa"
echo "opteniendo energias"
./get_energies
echo "energias optenidas"
echo "generando el histograma"
gnuplot plot_histogram.gnu
echo "histograma creado en el archivo energy_histogram.png"
