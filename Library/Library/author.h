#pragma once
#include <string>
class author
{
	int id;
	std::string name;
	int birth;
public:
	void print_author();
	author(int id, std::string name, int birth) {
		this->id = id;
		this->name = name;
		this->birth = birth;
	}
};

