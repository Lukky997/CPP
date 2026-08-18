#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	typedef AForm * (Intern::*CreatorFunc)(std::string);

	CreatorFunc creator[] = {
		&Intern::createShruberry,
		&Intern::createPardon,
		&Intern::createRobotomy
	};

	std::string tab[] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};

	for (int i = 0; i < 3; i++)
	{
		if (tab[i] == formName)
		{
			std::cout << "Intern create the form " << formName << std::endl;
			return ((this->*creator[i])(target));
		}
	}
	throw UnknownFormException();
}

AForm *Intern::createShruberry(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

const char *Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form type");
}