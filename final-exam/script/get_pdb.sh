#!/bin/bash

folder_doking_results="../docking_results"
vinaout_to_pdb="../vinaout_to_pdb.sh"

find  "$folder_doking_results" -type f -name "*.pdbqt" | while read -r file; do
  echo "Transformando pdbqt ($file) a pdb"
  "$vinaout_to_pdb" "$file"  
done

