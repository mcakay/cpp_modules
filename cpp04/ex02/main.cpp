#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	AAnimal *animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	AAnimal *copy = new Cat((Cat&)animals[0]);
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
	}
	std::cout << "animals[0] address: " << animals[0] << std::endl;
	std::cout << "copy address: " << copy << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	return (0);
}