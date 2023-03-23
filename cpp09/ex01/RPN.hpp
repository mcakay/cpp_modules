#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rpn);
		void getResult(const std::string &input);
		bool checkInput(const std::string &input);
		void error(void);
};

#endif