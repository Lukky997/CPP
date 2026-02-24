#include "../includes/phonebook.hpp"

std::string	getInput(const std::string &prompt)
{
	std:: string input;

	std::cout << prompt;
	std::getline(std::cin, input);

	while (input.empty())
	{
		std::cout << "This field cannot be empty.\n" << prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

int	getIndex()
{
	std:: string input;
	int index;

	while(true)
	{
		std::cout << "Enter the index of the contact: ";
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << "This field cannot be empty." << std::endl;
            continue;
        }

		bool isDigit = true;
		index = 0;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				isDigit = false;
				break;
			}
			index = index * 10 + (input[i] - '0');
		}

		if (!isDigit)
		{
			std::cout << "Only numbers are allowed." << std::endl;
			continue;
		}
		return (index);
	}
}

std::string getPhoneNumber()
{
	std::string phoneNumber;

	while(1)
	{
		std::cout << "What is your phone number : ";
		std::getline(std::cin, phoneNumber);

		if (phoneNumber.empty())
		{
			std::cout << "This field cannot be empty. Please enter again: ";
			std::getline(std::cin, phoneNumber);
		}

		bool valid = true;
		for (size_t j = 0; j < phoneNumber.size(); j++)
		{
			if (!isdigit(phoneNumber[j]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
		{
			std::cout << "Please enter digits only." << std::endl;
			continue;
		}
		return (phoneNumber);
	}
}

PhoneBook::PhoneBook()
{
    count = 0;
    index = 0;
}

void PhoneBook::addContact()
{
	std::string firstName, lastName, nickName, phoneNumber, darknestSecret;

	firstName = getInput("What is your first name : ");
	lastName = getInput("What is your last name : ");
	nickName = getInput("What is your nickname : ");
	phoneNumber = getPhoneNumber();
	darknestSecret = getInput("What is your darknest secret : ");

	contacts[index].setFirstName(firstName);
	contacts[index].setLastName(lastName);
	contacts[index].setNickName(nickName);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarknestSecret(darknestSecret);

	index = (index + 1) % 8;

	if (count < 8)
		count++;
	std::cout << "The contact has been successfully created!" << std::endl;
}

std::string formatField(const std::string &str)
{
    std::string display;

    if (str.length() > 10)
        display = str.substr(0, 9) + ".";
    else
        display = str;

    size_t spaces = 10 - display.length();
    return std::string(spaces, ' ') + display;
}

void	PhoneBook::showContact(int i)
{
	std::cout << "First name : " << contacts[i].getFirstName() << std::endl;
	std::cout << "Last name : " << contacts[i].getLastName() << std::endl;
	std::cout << "Nickname : " << contacts[i].getNickName() << std::endl;
	std::cout << "Phone number : " << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darknest secret : " << contacts[i].getDarknestSecret() << std::endl;
}

void	PhoneBook::showTable()
{
	int output;

	std::cout << "===============================================" << std::endl;
	std::cout << "||  INDEX   |FIRST NAME| LASTNAME | NICKNAME ||" << std::endl;
	std::cout << "===============================================" << std::endl;
	for(int i = 0; i < count; i++)
	{
    	std::cout << "||    "
            << i << "     |"
            << formatField(contacts[i].getFirstName()) << "|"
            << formatField(contacts[i].getLastName()) << "|"
            << formatField(contacts[i].getNickName()) << "||" 
            << std::endl;
	}
	std::cout << "===============================================" << std::endl;
	output = getIndex();
	if (output < 0 || output >= count)
    {
        std::cout << "Index out of range! Must be between 0 and " << count-1 << "." << std::endl;
        return;
    }
	showContact(output);
}

void PhoneBook::searchContact()
{
	if (count == 0) { 
		std::cout << "No contacts in the phonebook." << std::endl;
		return;
	}
	showTable();
}
