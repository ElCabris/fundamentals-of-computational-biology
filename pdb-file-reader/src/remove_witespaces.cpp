#include <atom.hpp>

std::string remove_whitespace(const std::string &str) {
	std::string result = "";
	
	for (char c : str) {
		if (!std::isspace(c))
			result += c;
	}
	return result;
}
