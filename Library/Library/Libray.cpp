#include "Libray.h"
#include "user.h"
#include "book.h"
#include "author.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool Libray::get_command() {
	//std::cout << "wtf ";
	//read_data();
	string arr[4];
	std::string command;
	//std::cin >> arr[0];
	std::getline(std::cin, command);
	int i = 0;
	//cout << command << endl;
	std::stringstream ssin(command);
	while (ssin.good() && i < 4) {//dzielimy string na oddzielne slowa
		ssin >> arr[i];
		//cout << "make arr" << arr[i] << endl;
		++i;
	}
	if (arr[0] == "borrow") {
		//cout << "arr" << arr[0] << " borrow\n";
		borrow(arr);
	} else if (arr[0] == "delete") {
		cout << arr[0] << " delete\n";
		del(arr);
	} else if (arr[0] == "print") {
		print(arr);
	} else if (arr[0] == "help") {
		print_help();
	}else if (arr[0] == "add") {
		add(arr);
	}else if (arr[0] == "exit") {
		return false;
	} else {
		cout << "Commend " << arr[0] << " not supported.\n Check for typeos.\n";
	}
	return true;
}

void Libray::add(std::string arg[]) {
	if (arg[1] == "user") {
		add_user(std::stoi(arg[2]), arg[3]);
	}
	else if (arg[1] == "book") {//print all book data
		cout << "Title Author Status\n";
		for (book b : books) {
			b.print_book();
		}
	}
	else if (arg[1] == "author") {
		cout << "Name Id Birth\n";//print all authors
		for (author a : authors) {
			a.print_author();
		}
	}
}

void Libray::add_user(int id, std::string name) {
	user u = user(id, name);
	users.push_back(u);
}

void Libray::add_book(int id, std::string name, std::string author_name) {
	book b = book(id, name, author_name, 0);
	books.push_back(b);
}

void Libray::add_author(int id, std::string name, int birth) {
	author a = author(id, name, birth);
}

void Libray::read_data() {
	std::ifstream infile("test.users.txt");//data about users
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		int a;
		std::string b;
		if (!(iss >> a >> b)) { break; } // error
		user u = user(a, b);
		users.push_back(u);
		// process pair (a,b)
	}
	std::ifstream infile2("test.authors.txt");//authors data
	//std::string line;
	while (std::getline(infile2, line))
	{
		std::istringstream iss(line);
		int a;
		std::string b;
		int birth;
		if (!(iss >> a >> b >> birth)) { break; } // error
		author u = author(a, b, birth);
		authors.push_back(u);
		// process pair (a,b)
	}
	std::ifstream infile3("test.books.txt");//book data
	//std::string line;
	while (std::getline(infile3, line))
	{
		std::istringstream iss(line);
		int a;
		std::string b;
		std::string c;
		int d;
		if (!(iss >> a >> b >> c >> d)) { break; } // error
		book u = book(a, b, c, d);
		books.push_back(u);
		// process pair (a,b)
	}
}

void Libray::print(string arg[]) {
	if (arg[1] == "users") {
		print_users();
	} else if (arg[1] == "books") {//print all book data
		cout << "Title Author Status\n";
		for (book b : books) {
			b.print_book();
		}
	}else if (arg[1] == "authors") {
		cout << "Name Id Birth\n";//print all authors
		for (author a : authors) {
			a.print_author();
		}
	}
}

void Libray::print_users() {
	cout << "Name Id Status\n";
	for (user u : users) {//print all user data
		u.print_user();
	}
}

void Libray::print_help() {
	cout << "Commands:\n";
	cout << "print <data_type> - prints selected data table\n";
	cout << "\t<data_type> users books authors\n";
	cout << "add <data_type> <params...> - deletes element by id\n";
	cout << "\t<data_type> - user book author\n";
	cout << "\tuser <params...>:\n";
	cout << "\t\t<id>user id\n";
	cout << "\t\t<name>user name\n";
	cout << "\tbook <params...>:\n";
	cout << "\t\t<id>book id\n";
	cout << "\t\t<name>book title\n";
	cout << "\t\t<author_name>name of book's author\n";
	cout << "\tauthor <params...>:\n";
	cout << "\t\t<id>author id\n";
	cout << "\t\t<name>author name\n";
	cout << "\t\t<birth>year the author was born\n";
	cout << "delete <data_type> <id> - deletes element by id\n";
	cout << "\t<data_type>user\n";
	cout << "\t<id>element id\n";
}

void Libray::borrow(string arg[]) {
	for (book b: books) {
		if (b.name == arg[1]) {//find the user with given name
			b.borrowed = true;
			b.borrowed_by = std::stoi(arg[2]);
			return;
		}
	}
	cout << "Book " << arg[1] << " not found.\n";
}

void Libray::return_book(string arg[]) {
	for (book b : books) {
		if (b.name == arg[1]) {//find the user with given name
			b.borrowed = true;
			b.borrowed_by = 0;
		}
	}
	cout << "Book " << arg[1] << " not found.\n";
}

void Libray::delete_user(string arg[]) {
	int i = 0;
	for (user u : users) {
		if (u.id == std::stoi(arg[2])) {//find the user with given id
			users.erase(users.begin() + i);//delete user at index "i"
			return;
		}
		i++;
	}
	cout << "User with id " << arg[2] << " not found.\n";
}

void operation_not_supported(string t) {
	cout << "Operation not supported for type " << t << endl;
}

void Libray::del(string arg[]) {
	if (arg[1] == "user") {
		delete_user(arg);
		return;
	}
	operation_not_supported(arg[1]);//none of supported types match
}
