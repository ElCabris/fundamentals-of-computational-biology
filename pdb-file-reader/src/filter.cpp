#include <atom.hpp>
#include <algorithm>

std::vector<Atom> filter_atoms(const std::vector<Atom> &atoms, std::function<bool (Atom)> filter) {
	std::vector<Atom> result;
	std::copy_if(atoms.begin(), atoms.end(), std::back_inserter(result), filter);	
	return result;
}

