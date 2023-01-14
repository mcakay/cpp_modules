#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){}
		MutantStack &operator=(const MutantStack &other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { 
			return std::stack<T>::c.begin(); 
		}
		iterator end() { 
			return std::stack<T>::c.end(); 
		}
};

#endif