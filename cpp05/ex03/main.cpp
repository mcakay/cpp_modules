#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *form;
	Bureaucrat *bureaucrat;
	bureaucrat = new Bureaucrat("Melih", 1);
	form = someRandomIntern.makeForm("shrubbery creation", "Bender");
	bureaucrat->signForm(*form);
	bureaucrat->executeForm(*form);
	delete bureaucrat;
	delete form;
	return 0;
}