#pragma once
#include <string>
class user
{
	int id;
	std::string name;
public:
	void print_user();
	user(int id, std::string name) {
		this->id = id;
		this->name = name;
	}
};