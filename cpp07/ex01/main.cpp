#include "iter.hpp"

template <typename T>
void iter(T *array, int length, T f(T e))
{
	for (int i = 0; i < length; i++)
	{
		array[i] = f(array[i]);
	}
}

int addOne(int e)
{
	return e + 1;
}

double addOne(double e)
{
	return e + 1.0;
}

int main(void)
{
	int array[5] = {1, 2, 3, 4, 5};
	iter(array, 5, &addOne);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;
	double array2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(array2, 5, &addOne);
	for (int i = 0; i < 5; i++)
		std::cout << array2[i] << std::endl;
	return 0;
}