#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	validateGrade();
}

Form::~Form(void)
{
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

void Form::validateGrade(void) const
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
	o << "Form " << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no") << ", grade required to sign: " << f.getGradeToSign() << ", grade required to execute: " << f.getGradeToExecute();
	return (o);
}