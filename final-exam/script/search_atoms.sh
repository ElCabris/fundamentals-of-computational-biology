#!/bin/bash

folder_doking_pdb="../docking_results"
protein="../protein/protein.pdb"
results_file="results.csv"

touch "$results_file" 

find "$folder_doking_pdb" -type f -name  "*.pdb" | while read -r ligand; do

	echo "filter_ligand $ligand $protein $results_file"
	./filter_ligand "$protein" "$ligand" "$results_file" 
done

echo "Results in results.csv"
