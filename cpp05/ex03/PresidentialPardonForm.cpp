#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor)
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox!" << std::endl;
}