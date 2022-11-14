#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				std::cout << (char)(argv[i][j] - 32);
			else
				std::cout << (char)argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}
