#include <atom.hpp>
#include <fstream>
#include <iostream>

std::vector<Atom> read_pdb(const std::string &file_name) {
  std::ifstream file(file_name);
  std::vector<Atom> atoms;
  std::string line;

  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << file_name << std::endl;
    return atoms;
  }

  while (std::getline(file, line)) {

    if (line.substr(0, 4) == "ATOM" || line.substr(0, 6) == "HETATM") {
      Atom atom;
      atom.serial_number = std::stoi(remove_whitespace(line.substr(6, 5)));
      atom.name = remove_whitespace(line.substr(12, 4));
      atom.alternate_location_indicator = line[16];
      atom.residue_name = remove_whitespace(line.substr(17, 3));
      atom.chain_identifier = line[21];
      atom.residue_sequence_number =
          std::stoi(remove_whitespace(line.substr(22, 4)));
			atom.code_for_insertions_of_residues = line[26];
			atom.x_ortogonal_coordinate = std::stof(remove_whitespace(line.substr(30, 8)));
			atom.y_ortogonal_coordinate = std::stof(remove_whitespace(line.substr(38, 8)));
			atom.z_ortogonal_coordinate = std::stof(remove_whitespace(line.substr(46, 8)));
			atom.occupancy = std::stof(remove_whitespace(line.substr(54, 6)));
			atom.temperature_factor = std::stof(remove_whitespace(line.substr(60, 6)));
			atom.segment_identifier = remove_whitespace(line.substr(72, 4));
			atom.element_symbol = remove_whitespace(line.substr(76, 2));
			atom.charge = remove_whitespace(line.substr(78, 2));
			atoms.push_back(atom);
		}
  }
	file.close();
	return atoms;
}
