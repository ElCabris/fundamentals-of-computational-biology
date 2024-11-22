#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

namespace fs = std::filesystem;

std::vector<fs::path> find_pdbqt_files(const fs::path &directory) {
  std::vector<fs::path> pdbqt_files;

  if (fs::exists(directory) && fs::is_directory(directory)) {
    for (const auto &entry : fs::recursive_directory_iterator(directory)) {
      if (entry.is_regular_file() && entry.path().extension() == ".pdbqt")
        pdbqt_files.push_back(entry.path());
    }
  } else
    std::cerr << "Error: The path specified is invalid or is not a directory"
              << std::endl;

  return pdbqt_files;
}

std::unordered_map<float, int>
extract_energies(std::vector<fs::path> pdbqt_files) {
  std::unordered_map<float, int> energy_count;
  std::regex energy_pattern(R"(REMARK VINA RESULT:\s+([-+]?[0-9]*\.?[0-9]+))");
  std::smatch match;

  for (const auto &file_path : pdbqt_files) {
    std::ifstream file(file_path);
    std::string line;

    if (!file.is_open()) {
      std::cerr << "could not open file: " << file_path << std::endl;
      continue;
    }

    while (std::getline(file, line)) {
      if (std::regex_search(line, match, energy_pattern)) {
        float energy = std::stof(match[1].str());
        energy_count[energy]++;
      }
    }
  }

  return energy_count;
}

void plot_histogram(const std::unordered_map<float, int> &energy_count) {
  std::ofstream data_file("energy_histogram.dat");

  if (!data_file.is_open()) {
    std::cerr << "coul not open temporal file: " << std::endl;
    return;
  }

  for (const auto &[energy, count] : energy_count)
    data_file << energy << ' ' << count << std::endl;

  data_file.close();
}

int main() {
  fs::path directory = "../docking_results";

  auto paths = find_pdbqt_files(directory);
  auto energies = extract_energies(paths);
  plot_histogram(energies);
  return 0;
}
