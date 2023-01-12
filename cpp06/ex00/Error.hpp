#ifndef ERROR_HPP
# define ERROR_HPP

# include <iostream>

class Error
{
	public:
		Error();
		~Error();
		Error(Error const &src);
		Error &operator=(Error const &other);
		void error(std::string message, int exitCode);
		void checkArguments(int argc);
		void checkInput(std::string input);
		void checkCharacters(std::string input);
		void checkDot(std::string input);
		void checkf(std::string input);
		void checkPlusMinus(std::string &input);
		int checkRange(std::string type, std::string input);

};

#endif