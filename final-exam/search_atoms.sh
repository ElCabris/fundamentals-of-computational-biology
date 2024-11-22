#!/bin/bash

folder_doking_pdb="./docking_results"
protein="./protein/protein.pdb"
results_file="results.txt"

find "$folder_doking_pdb" -type f -name  "*01.pdb" | while read -r ligand; do

	echo "filter_ligand $ligand $protein $results_file"
	./filter "$protein" "$ligand" "$results_file"
done

echo "Results in $(results_file)"
