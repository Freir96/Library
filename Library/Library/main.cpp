#include "Libray.h"
#include <iostream>

int main()
{
    std::cout << "Type \"help\" for command list and \"exit\" to end process.\n";
	Libray l;
	l.read_data();
	bool go_on = true;
	while (go_on) {
		std::cout << "> ";
		go_on = l.get_command();
	}
}
