#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &rpn)
{
	this->stack = rpn.stack;
	return *this;
}

bool RPN::checkInput(const std::string &input)
{
	std::string legal = "0123456789+-/* ";
	for (size_t i = 0; i < input.length(); i++)
	{
		size_t index = legal.find(input[i]);
		if (index == std::string::npos)
			return false;
	}
	return true;
}

void RPN::error(void)
{
	std::cout << "Error" << std::endl;
	exit(1);
}

void RPN::getResult(const std::string &input)
{
	if (this->checkInput(input) == false)
	{
		throw std::invalid_argument("err");
		return ;
	}
	std::stringstream ss(input);
	std::string item;
	std::string operators = "+-*/";
	int temp;
	while (getline(ss, item, ' '))
	{
		size_t index = operators.find(item);
		if (index != std::string::npos)
		{
			if (this->stack.size() < 2)
				error();
			temp = this->stack.top();
			this->stack.pop();
			int top = this->stack.top();
			this->stack.pop();
			switch (index)
			{
				case 0:
					top += temp;
					break;
				case 1:
					top -= temp;
					break;
				case 2:
					top *= temp;
					break;
				case 3:
					top /= temp;
					break;
			}
			this->stack.push(top);
		}
		else
			this->stack.push(std::stoi(item));
	}
	if (this->stack.size() != 1)
		this->error();
	std::cout << this->stack.top() << std::endl;
}