#!/bin/bash
#
# Splits an Autodock Vina output file (PDBQT) into separate models
# and writes them as PDB files.
# Flexible protein residues, if present, are written out together with the ligand.

# ********************************************************************************

# Input (in the command line): Name of the vina output file

if [ $# -lt 1 ]; then
   echo "Usage:"
   echo ""
   echo "vinaout_to_pdb.sh  vina_output_file"
   echo ""
   exit -1
fi

inputfile=$1
rootname=${inputfile%.pdbqt}

# Copy all MODEL, ATOM and HETATM records, as well as the VINA RESULT REMARK,
# from the PDBQT file to a new PDB file

grep 'MODEL\|ATOM\|HETATM\|RESULT' ${inputfile} > ${rootname}.pdb

grep 'RESULT' ${inputfile} > ${rootname}.score

# Calculate the number of lines for splitting

flines=$(cat ${rootname}.pdb | wc -l)
nmodel=$(grep -c MODEL ${rootname}.pdb)
let "nlines = $flines/$nmodel"

split --numeric-suffixes=1 -a 2 -l $nlines ${rootname}.pdb ${rootname}_out_

rm ${rootname}.pdb

#Rename to add .pdb suffix
for file in ${rootname}_out_*
  do mv $file $file.pdb
done



