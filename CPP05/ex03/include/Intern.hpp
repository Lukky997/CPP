#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	private:
		AForm *createShruberry(std::string target);
		AForm *createPardon(std::string target);
		AForm *createRobotomy(std::string target);

	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);
		Intern &operator=(Intern const &copy);

		AForm *makeForm(const std::string &formName, const std::string &target);

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif