#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int arr_size;
	public:
		Array()
		{
			arr = new T[0];
			arr_size = 0;
		}
		~Array()
		{
			delete[] arr;
		}
		Array(unsigned int n)
		{
			arr = new T[n];
			arr_size = n;
		}
		Array(const Array &copy)
		{
			*this = copy;
		}
		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] arr;
				arr = new T[arr_size];
				for (unsigned int i = 0; i < arr_size; i++)
					arr[i] = other.arr[i];
			}
			return *this;
		}
		T &operator[](unsigned int i)
		{
			if (i >= arr_size || i < 0)
				throw std::exception();
			return arr[i];
		}
		unsigned int size() const
		{
			return arr_size;
		}
};

#endif