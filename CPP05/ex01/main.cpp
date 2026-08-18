#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat alice("Alice", 42);
		Form paper("Paper", 40, 10);

		std::cout << alice << std::endl;
		std::cout << paper << std::endl;
		alice.signForm(paper);
		std::cout << paper << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 100);
		Form hard("Hard", 50, 25);

		std::cout << low << std::endl;
		std::cout << hard << std::endl;
		low.signForm(hard);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form invalid("Invalid", 0, 10);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}