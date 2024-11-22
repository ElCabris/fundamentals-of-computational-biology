#include <atom.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

std::string get_filename_without_extension(const std::string &path) {
  std::filesystem::path file_path(path);
  return file_path.stem().string();
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "invalid arguments" << std::endl;
    return 1;
  }
  auto protein = read_pdb(argv[1]);
  auto ligand = read_pdb(argv[2]);

  auto protein_filter = [&ligand](const Atom &a) -> bool {
    for (const auto &it : ligand) {
      if (calculate_distance(it, a) < 4)
        return true;
    }
    return false;
  };
  auto protein_filtered = filter_atoms(protein, protein_filter);

  std::ofstream file(argv[3], std::ios::app);
  if (!file.is_open()) {
    std::cerr << "colud not open file " << argv[3] << std::endl;
    return -1;
  }

  file << get_filename_without_extension(argv[2]) << ": "
       << protein_filtered.size() << std::endl;

  for (const auto &i : protein_filtered) {
    auto min_dist = minimum_distance(ligand, i);
    for (const auto &j : ligand) {
      if (calculate_distance(i, j) == min_dist) {
        file << i.residue_name << i.residue_sequence_number << ' ' << j.name
             << ' ' << min_dist << std::endl;
      }
    }
  }
  file.close();

  return 0;
}
