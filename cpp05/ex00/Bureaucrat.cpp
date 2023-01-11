#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default") {
	this->grade = 150;
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

const std::string &Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &instance) {
	o << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return o;
}