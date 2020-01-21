#pragma once
#include <string>
class book
{
	int id;
	std::string name;
	std::string author_name;
	int author_id;
	bool borrowed;
	int borrowed_by;
	void borrow(int user_id);
	void return_b(int user_id);
	void print_book();
};

