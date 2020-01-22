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
public:
	void borrow(int user_id);
	void return_b(int user_id);
	void print_book();
	book(int id, std::string name, std::string author_name, int borrowed_by) {
		this->id = id;
		this->name = name;
		this->author_name = author_name;
		this->borrowed = borrowed_by != 0;
		this->borrowed_by = borrowed_by;
	}
};

