#include "user.h"
#include <iostream>
#include <iomanip> 

void user::print_user() {
	size_t headerWidths[3] = {
		std::string("Name").size(),
		std::string("id").size(),
		std::string("Status").size()
	};
	std::cout << std::left << std::setw(headerWidths[0]) << name;
	// Spacing between first and second header.
	std::cout << "   ";
	std::cout << std::right << std::setw(headerWidths[1]) << id
		<< " " << std::setw(headerWidths[2]) << "active" << std::endl;
}
