#include <iostream>
#include <string>
#include "../includes/contact.hpp"
#include "../includes/phonebook.hpp"

int main()
{
	std::string command;
	PhoneBook pb = PhoneBook();

	std::cout << "Welcome to your Phone Book !" << std::endl;
	while(1)
	{
		std::cout << "ADD | SEARCH | EXIT\nEnter a command -> ";
		std::getline(std::cin, command);
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "\nNot a valid command!\n" << std::endl;
	}
	return (0);
}
