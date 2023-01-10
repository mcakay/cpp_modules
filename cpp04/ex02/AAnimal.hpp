#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string type;
		AAnimal();
		AAnimal(const AAnimal &other);
	public:
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &other);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif