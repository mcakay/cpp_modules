#include <iostream>

int main(void)
{
	std::string name = "melih";
	std::string *stringPTR = &name;
	std::string &stringREF = name;
	std::cout << "Address of the string variable: " << &name << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;
	std::cout << "Value of the string variable: " << name << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}