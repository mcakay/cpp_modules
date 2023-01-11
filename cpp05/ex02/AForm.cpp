#include "AForm.hpp"

AForm::~AForm()
{

}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :  name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if  (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Name and grades are const and can't be overwritten" << std::endl;
	this->isSigned = other.gradeToSign;
	return *this;
}

std::string AForm::getName()
{
	return this->name;
}

bool AForm::getIsSigned()
{
	return this->isSigned;
}

int AForm::getGradeToSign()
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute()
{
	return this->gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}