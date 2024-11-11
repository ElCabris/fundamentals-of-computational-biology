#include <atom.hpp>
#include <cmath>

float calculate_distance(const Atom &atom1, const Atom &atom2) {
  return std::sqrt(
      std::pow(atom1.x_ortogonal_coordinate - atom2.x_ortogonal_coordinate, 2) +
      std::pow(atom1.y_ortogonal_coordinate - atom2.y_ortogonal_coordinate, 2) +
      std::pow(atom1.z_ortogonal_coordinate - atom2.z_ortogonal_coordinate, 2));
}
