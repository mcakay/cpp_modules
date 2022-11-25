#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./zombieHorde [number of zombies]" << std::endl;
		return (1);
	}
	int N = atoi(argv[1]);
	if (N < 1)
	{
		std::cout << "Number of zombies must be greater than 0" << std::endl;
		return (2);
	}
	Zombie* zombies = zombieHorde(N, "melih");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
