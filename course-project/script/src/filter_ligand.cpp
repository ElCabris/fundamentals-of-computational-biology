#include <atom.hpp>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>

std::string get_filename_without_extension(const std::string &path) {
  std::filesystem::path file_path(path);
  return file_path.stem().string();
}

int main(int argc, char *argv[]) {

  // argv[1] = protein
  // argv[2] = ligand
  // argv[3] = output file

  if (argc != 4) {
    std::cerr << "invalid arguments" << std::endl
              << "ligando " << "proteina" << std::endl;
    return -1;
  }
  // lectura del ligando y la proteina
  auto ligand = read_pdb(argv[2]);
  auto protein = read_pdb(argv[1]);

  // filtro de la proteina (O, N)
  auto filter_protein = [](const Atom &a) -> bool {
    if (a.name.starts_with("O") || a.name.starts_with("N"))
      return true;
    return false;
  };

  // proteina despues de aplicar el filtro
  auto protein_filtered = filter_atoms(protein, filter_protein);

  // filtro del ligando
  auto filter_ligand = [&protein_filtered](const Atom &a) -> bool {
    if ((a.name.starts_with("O") || a.name.starts_with("N") ||
         a.name.starts_with("S") || a.name.starts_with("F")) &&
        minimum_distance(protein_filtered, a) < 3.5)
      return true;
    return false;
  };

  // ligando despues de aplicar el filtro
  auto ligand_filter = filter_atoms(ligand, filter_ligand);

  if (ligand_filter.size() > 0) {
    // escribir el archivo csv
    std::ofstream file(argv[3], std::ios::app);

    if (!file.is_open()) {
      std::cerr << "could not open file " << argv[3] << std::endl;
      return 1;
    }

    // buscar cada ligando
    for (const auto &i : ligand_filter) {
      auto dis_min = minimum_distance(protein_filtered, i);
      assert(dis_min < 3.5);

      file << get_filename_without_extension(argv[2]) << ',' << i.name << ',';
      // buscar cada proteina

      for (const auto &j : protein_filtered) {
        if (calculate_distance(j, i) == dis_min) {
          file << j.name << ',' << j.residue_name << ','
               << j.residue_sequence_number << ',';
          break;
        }
      }
      file << dis_min << '\n';
    }

    file.close();
  }
  return 0;
}
