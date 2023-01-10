#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal *animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
	{
		
		delete animals[i];
	}
	return (0);
}