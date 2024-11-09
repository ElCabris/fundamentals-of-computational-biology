#include "../include/atom.hpp"

float minimum_distance(const std::vector<Atom> &atoms, const Atom &atom) {
  float min_dis = calculate_distance(atoms[0], atom);

  for (const auto &it : atoms) {
    auto distance = calculate_distance(it, atom);
    if (distance < min_dis)
      min_dis = distance;
  }
  return min_dis;
}
