#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		virtual ~AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		std::string getName();
		bool getIsSigned();
		int getGradeToSign();
		int getGradeToExecute();
		virtual void execute(Bureaucrat const &executor) = 0;
		virtual void beSigned(Bureaucrat const &bureaucrat) = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{	
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif