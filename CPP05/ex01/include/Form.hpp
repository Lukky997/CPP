#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>
class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

		void validateGrade(void) const;

	public:
		Form(void);
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		~Form(void);
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif