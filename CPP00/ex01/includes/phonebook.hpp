#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <cctype>
#include <sstream>

class PhoneBook {
	private:
		Contact contacts[8];
		int index;
		int count;

		void showContact(int i);
		void showTable();

	public:
		PhoneBook();
		void addContact();
		void searchContact();
};

#endif