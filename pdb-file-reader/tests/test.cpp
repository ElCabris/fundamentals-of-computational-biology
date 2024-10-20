#include <iostream>
#include <atom.hpp>
int main() {
	auto atoms = read_pdb("4ph4.pdb");

	auto first_filter = [](Atom atom) -> bool {return atom.residue_name == "2UG";};
	auto result_filter = filter_atoms(atoms, first_filter);
	
	write_to_file(result_filter, "result.pdb");
	return 0;
}
