#pragma once
#include <string>
class author
{
public:
	int id;
	std::string name;
	int birth;
	void print_author();
	author(int id, std::string name, int birth) {
		this->id = id;
		this->name = name;
		this->birth = birth;
	}
};

