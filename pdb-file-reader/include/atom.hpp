#include <string>
#include <vector>
#include <functional>

struct Atom {
  int serial_number, residue_sequence_number;
  std::string name, alternate_location_indicator, residue_name,
      chain_identifier, code_for_insertions_of_residues, segment_identifier,
      element_symbol, charge;
  float x_ortogonal_coordinate, y_ortogonal_coordinate, z_ortogonal_coordinate,
      occupancy, temperature_factor;
};

std::vector<Atom> read_pdb(const std::string &file);

std::vector<Atom> filter_atoms(const std::vector<Atom>& atoms, std::function<bool(Atom)>);

std::string remove_whitespace(const std::string& str);

void write_to_file(const std::vector<Atom>& atoms);
