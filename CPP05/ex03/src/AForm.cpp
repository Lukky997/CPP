#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	validateGrade();
}

AForm::~AForm(void)
{
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

void AForm::validateGrade(void) const
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &a)
{
	o << "AForm " << a.getName() << ", signed: " << (a.getSigned() ? "yes" : "no") << ", grade required to sign: " << a.getGradeToSign() << ", grade required to execute: " << a.getGradeToExecute();
	return (o);
}