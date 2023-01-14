#include "Span.hpp"

Span::Span()
{
	this->N = 0;
	this->v = std::vector<int>();
}

Span::Span(unsigned int N)
{
	this->N = N;
	this->v = std::vector<int>();
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	this->N = other.N;
	this->v = other.v;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	try {
		if (this->v.size() == this->N)
			throw Span::FullException();
		this->v.push_back(n);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan()
{
	try
	{
		if (this->v.size() <= 1)
			throw Span::NoSpanException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}
	std::vector<int> v = this->v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 1; i < v.size() - 1; i++)
	{
		if (v[i + 1] - v[i] < min)
			min = v[i + 1] - v[i];
	}
	return min;
}

int Span::longestSpan()
{
	try
	{
		if (this->v.size() <= 1)
			throw Span::NoSpanException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}
	std::vector<int> v = this->v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

void Span::addRandomNumbers(unsigned int n)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			this->addNumber(rand() % ((i + 1) + 1) * -1);
		else if (i % 2 == 1)
			this->addNumber(rand() % (i + 1) + 1);
	}
}

const char *Span::FullException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Span has no span";
}