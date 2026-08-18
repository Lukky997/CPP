#include "include/Intern.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Intern intern;
		AForm *form1 = intern.makeForm("shrubbery creation", "home");
		AForm *form2 = intern.makeForm("robotomy request", "Bender");
		AForm *form3 = intern.makeForm("presidential pardon", "Arthur Dent");
		Bureaucrat boss("Boss", 1);

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		boss.signForm(*form1);
		boss.signForm(*form2);
		boss.signForm(*form3);
		boss.executeForm(*form1);
		boss.executeForm(*form2);
		boss.executeForm(*form3);
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Intern intern;
		AForm *invalid = intern.makeForm("unknown form", "target");
		delete invalid;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}