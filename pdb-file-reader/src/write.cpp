#include <atom.hpp>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

enum Alignment {
    RIGHT,
    LEFT,
};

std::string format_field(const std::string& data, int width, Alignment alignment) {
    std::ostringstream oss;
    if (alignment == RIGHT) {
        oss << std::right << std::setw(width) << data;
    } else {
        oss << std::left << std::setw(width) << data;
    }
    return oss.str();
}

void write_to_file(const std::vector<Atom>& atoms, const std::string& file_name) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura.");
    }

    for (const auto& atom : atoms) {
        std::ostringstream line;

        // Record name
        line << "ATOM  ";

        // Atom serial number (columns 7-11)
        line << format_field(std::to_string(atom.serial_number), 5, RIGHT) << " ";

        // Atom name (columns 13-16)
        line << format_field(atom.name, 4, LEFT);

        // Alternate location indicator (column 17)
        line << atom.alternate_location_indicator;

        // Residue name (columns 18-20)
        line << " " << format_field(atom.residue_name, 3, RIGHT) << " ";

        // Chain identifier (column 22)
        line << atom.chain_identifier << " ";

        // Residue sequence number (columns 23-26)
        line << format_field(std::to_string(atom.residue_sequence_number), 4, RIGHT);

        // Code for insertions of residues (column 27)
        line << " ";

        // X coordinate (columns 31-38)
        line << std::fixed << std::setw(8) << std::right << std::setprecision(3) << atom.x_ortogonal_coordinate;

        // Y coordinate (columns 39-46)
        line << std::fixed << std::setw(8) << std::right << std::setprecision(3) << atom.y_ortogonal_coordinate;

        // Z coordinate (columns 47-54)
        line << std::fixed << std::setw(8) << std::right << std::setprecision(3) << atom.z_ortogonal_coordinate;

        // Occupancy (columns 55-60)
        line << std::fixed << std::setw(6) << std::right << std::setprecision(2) << atom.occupancy;

        // Temperature factor (columns 61-66)
        line << std::fixed << std::setw(6) << std::right << std::setprecision(2) << atom.temperature_factor;

        // Segment identifier (columns 73-76)
        // Rellenar con espacios si es necesario
        line << "   " << format_field(atom.segment_identifier, 4, LEFT);

        // Element symbol (columns 77-78)
        line << format_field(atom.element_symbol, 2, RIGHT);

        // Charge (columns 79-80)
        line << format_field(atom.charge, 2, RIGHT);

        // Añadir la línea al archivo
        file << line.str() << "\n";
    }

    file.close();
}

