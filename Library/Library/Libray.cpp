#include "Libray.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Libray::get_command() {
	std::cout << "> ";
	std::string command;
	std::cin >> command;
	int i = 0;
	std::stringstream ssin(command);
	string arr[4];
	while (ssin.good() && i < 4) {//dzielimy string na oddzielne slowa
		ssin >> arr[i];
		++i;
	}
	if (arr[0] == "borrow") {
		cout << arr[0] << " borrow\n";
		borrow(arr);
	} else if (arr[0] == "delete") {
		cout << arr[0] << " delete\n";
		del(arr);
	} else if (arr[0] == "help") {
		print_help();
	} else if (arr[0] == "exit") {
		return false;
	} else {
		cout << "Commend " << arr[0] << "not supported.\n Check foe typeos.\n";
	}
	return true;
}

void print_help() {
	cout << "Commands:\n";
}

void borrow(string arg[]) {

}

void del(string arg[]) {

}