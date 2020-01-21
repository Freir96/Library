#include "book.h"
#include <iostream>
#include <iomanip> 

void book::borrow(int user_id) {
	borrowed = true;
	borrowed_by = user_id;
}

void book::return_b(int user_id) {
	borrowed = false;
	borrowed_by = 0;
}

void book::print_book() {
	size_t headerWidths[3] = {
		std::string("Title").size(),
		std::string("Author").size(),
		std::string("Status").size()
	};
	auto state = "";
	if (borrowed)
		state = "borrowed";
	else
		state = "free";
	std::cout << std::left << std::setw(headerWidths[0]) << name;
	// Spacing between first and second header.
	std::cout << "   ";
	std::cout << std::right << std::setw(headerWidths[1]) << author_name
		<< " " << std::setw(headerWidths[2]) << state << std::endl;
}