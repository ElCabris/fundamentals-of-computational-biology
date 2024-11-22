#!/bin/bash
echo "compiling programs"
g++ src/filter_ligand.cpp -Iinclude -Llibs -latom -o filter_ligand -std=c++20 -g
echo "compilation completed successfully"
