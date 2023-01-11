#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	if (name == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else if (name == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (name == "presidential pardon")
		return new PresidentialPardonForm(target);
	else
		throw Intern::UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "Unknown form";
}