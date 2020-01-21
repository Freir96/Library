#pragma once
#include "user.h"
#include "author.h"
#include "book.h"
#include <vector>
class Libray
{
	std::vector<book> books;
	std::vector<author> authors;
	std::vector<user> users;
public:
	bool get_command();
	void add_user(int id, std::string name);
	void add_book(int id, std::string name, int author_id);
	void add_author(int id, std::string name);
	void delete_user(int id);
	void delete_bok(int id);
	void delete_author(int id);
	void print_items();
};

