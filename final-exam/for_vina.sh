#!/bin/bash

# Define variables
PROTEIN="./protein/protein.pdbqt"  # Path to your protein file
LIGAND_DIR="ligands"     # Directory containing ligand files
OUTPUT_DIR="docking_results"  # Directory to store docking results
CONFIG="vina_config.txt" # Configuration file with Vina parameters

# Check if protein file exists
if [ ! -f "$PROTEIN" ]; then
    echo "Protein file $PROTEIN not found!"
    exit 1
fi

# Check if ligand directory exists
if [ ! -d "$LIGAND_DIR" ]; then
    echo "Ligand directory $LIGAND_DIR not found!"
    exit 1
fi

# Check if configuration file exists
if [ ! -f "$CONFIG" ]; then
    echo "Configuration file $CONFIG not found!"
    exit 1
fi

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Iterate over each ligand in the ligand directory
for LIGAND in "$LIGAND_DIR"/*.pdbqt; do
    # Get ligand filename without extension
    LIGAND_NAME=$(basename "$LIGAND" .pdbqt)

    # Create a specific output folder for each ligand
    LIGAND_OUTPUT="$OUTPUT_DIR/$LIGAND_NAME"
    mkdir -p "$LIGAND_OUTPUT"

    echo "Docking ligand $LIGAND_NAME..."

    # Run AutoDock Vina
		vina --receptor "$PROTEIN" \
         --ligand "$LIGAND" \
         --config "$CONFIG" \
         --out "$LIGAND_OUTPUT/${LIGAND_NAME}_out.pdbqt" \
         --log "$LIGAND_OUTPUT/${LIGAND_NAME}_log.txt"

    echo "Docking completed for $LIGAND_NAME. Results saved in $LIGAND_OUTPUT."
done

echo "All dockings completed. Results are in the $OUTPUT_DIR directory."

