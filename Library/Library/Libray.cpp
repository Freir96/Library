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
	} else if (arr[0] == "exit") {
		return false;
	} else {
		cout << "Commend " << arr[0] << " not supported.\n Check for typeos.\n";
	}
	return true;
}

void Libray::read_data() {
	std::ifstream infile("test.users.txt");
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
	std::ifstream infile2("test.authors.txt");
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
	std::ifstream infile3("test.books.txt");
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
	} else if (arg[1] == "books") {
		cout << "Title Author Status\n";
		for (book b : books) {
			b.print_book();
		}
	}else if (arg[1] == "authors") {
		cout << "Name Id Birth\n";
		for (author a : authors) {
			a.print_author();
		}
	}
}

void Libray::print_users() {
	cout << "Name Id Status\n";
	for (user u : users) {
		u.print_user();
	}
}

void Libray::print_help() {
	cout << "Commands:\n";
	cout << "print <data_type> - prints selected data table\n";
	cout << "\t<data_type>users books authors\n";
}

void Libray::borrow(string arg[]) {

}

void Libray::del(string arg[]) {

}