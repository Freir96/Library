#pragma once
#include "user.h"
#include "author.h"
#include "book.h"
#include <vector>
using namespace std;

class Libray
{
public:
	std::vector<book> books;
	std::vector<author> authors;
	std::vector<user> users;
	bool get_command();
	void add(std::string arg[]);
	void add_user(int id, std::string name);
	void add_book(int id, std::string name, std::string author_name);
	void add_author(int id, std::string name, int birth);
	void delete_user(string arg[]);
	void delete_bok(int id);
	void delete_author(int id);
	void print_items();
	void print_users();
	void print(std::string arg[]);
	void borrow(string arg[]);
	void return_book(string arg[]);
	void del(string arg[]);
	void print_help();
	void read_data();
};

