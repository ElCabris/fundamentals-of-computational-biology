#!/bin/bash
echo "compiling program"
g++ src/main.cpp -Iinclude -Llibs -latom -o atoms -std=c++20
echo "compilation completed successfully, to run type ./atoms <ligand> <protein> <output>"
