#include "Libray.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	Libray l;
	bool go_on = l.get_command();
	while (go_on) {
		go_on = l.get_command();
	}
}
