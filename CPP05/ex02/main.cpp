#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("home");

		std::cout << gardener << std::endl;
		std::cout << shrub << std::endl;
		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat worker("Worker", 50);
		RobotomyRequestForm robot("Bender");

		std::cout << worker << std::endl;
		std::cout << robot << std::endl;
		worker.signForm(robot);
		worker.executeForm(robot);
		worker.executeForm(robot);
		worker.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << boss << std::endl;
		std::cout << pardon << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}