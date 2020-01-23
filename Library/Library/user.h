#pragma once
#include <string>
class user
{
public:
	int id;
	std::string name;
	void print_user();
	user(int id, std::string name) {
		this->id = id;
		this->name = name;
	}
};