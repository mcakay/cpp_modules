#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat(const std::string &name, int grade);
		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &instance);

#endif