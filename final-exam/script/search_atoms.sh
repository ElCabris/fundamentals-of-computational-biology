#!/bin/bash

folder_doking_pdb="../docking_results"
protein="../protein/protein.pdb"
output_folder="results"

mkdir -p "$output_folder"


find "$folder_doking_pdb" -type f -name  "*.pdb" | while read -r ligand; do

	filename=$(basename "$ligand")
	filename_noext="${filename%.pdb}"

	echo "atoms $ligand $protein $filename_noext"
	./atoms "$protein" "$ligand" "$output_folder/$filename_noext".pdb
done
