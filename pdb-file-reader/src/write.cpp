#include <atom.hpp>
#include <fstream>
#include <string>

enum Alignment {
	RIGHT,
	LEFT,
};

int calcule_blank_spaces(const std::string& string, int available_space) {
	return available_space - string.size();
}

std::string add_blank_spaces(int blank_spaces) {
	std::string result = "";
	for (auto i = 0; i < blank_spaces; ++i) {
		result += ' ';
	}
	return result;
}

std::string align(const std::string& data, int blank_spaces, Alignment alignment) {
	std::string result = "";
	if (alignment == RIGHT) {
		add_blank_spaces(blank_spaces);
		result += data;
	}

	else if (alignment == LEFT) {
		result += data;
		add_blank_spaces(blank_spaces);
	}

	return result;
}


void write_to_file(const std::vector<Atom>& atoms, const std::string& file_name) {
	std::ofstream file(file_name);

	for (auto atom : atoms) {
		file << "ATOM  ";
		// atom serial number
		auto aux = std::to_string(atom.serial_number); 
		file << align(aux, calcule_blank_spaces(aux, 5), RIGHT);
		
		// atom name
		file << align(atom.name, calcule_blank_spaces(atom.name, 4), LEFT);
		
		// Alternate location indicator
		file << atom.alternate_location_indicator;

		// Residue name
		file << align(atom.residue_name, calcule_blank_spaces(atom.residue_name, 3), RIGHT);

		// Chain identifier
		file << atom.chain_identifier;

		// Residue sequence number
		aux = std::to_string(atom.residue_sequence_number);
		file << align(aux, calcule_blank_spaces(aux, 4), RIGHT);

		// Code for insertions of residues
		file << atom.code_for_insertions_of_residues;

		// X orthogonal A coordinate
		aux = std::to_string(atom.x_ortogonal_coordinate);
		file << align(aux, calcule_blank_spaces(aux, 8), RIGHT);

		// Y orthogonal A coordinate
		aux = std::to_string(atom.y_ortogonal_coordinate);
		file << align(aux, calcule_blank_spaces(aux, 8), RIGHT);

		// Z orthogonal A coordinate
		aux = std::to_string(atom.z_ortogonal_coordinate);
		file << align(aux, calcule_blank_spaces(aux, 8), RIGHT);

		// occupancy
		aux = std::to_string(atom.occupancy);
		file << align(aux, calcule_blank_spaces(aux, 6), RIGHT);

		// Temperature factor
		aux = std::to_string(atom.temperature_factor);
		file << align(aux, calcule_blank_spaces(aux, 6), RIGHT);

		// Segment identifier
		file << align(atom.segment_identifier, calcule_blank_spaces(atom.segment_identifier, 4), LEFT);

		// Element symbol
		file << align(atom.element_symbol, calcule_blank_spaces(atom.element_symbol, 2), RIGHT);
		
		// Charge
		file << atom.charge;

		file << '\n';
	}
}
