#include <atom.hpp>
#include <iostream>

int main(int argc, char *argv[]) {

  // argv[1] = protein
  // argv[2] = ligand
  // argv[3] = output file

  if (argc != 4) {
    std::cerr << "invalid arguments" << std::endl
              << "ligando " << "proteina" << std::endl;
    return -1;
  }
  auto ligando = read_pdb(argv[2]);
  auto protein = read_pdb(argv[1]);

  auto filter_protein = [&](const Atom &a) -> bool {
    std::cout << minimum_distance(ligando, a);
    if ((a.name.starts_with("O") || a.name.starts_with("N") ||
         a.name.starts_with("S") || a.name.starts_with("F")) &&
        minimum_distance(protein, a) < 3.5)
      return true;
    return false;
  };

  filter_atoms(protein, filter_protein);

  write_to_file(protein, argv[3]);
  return 0;
}
