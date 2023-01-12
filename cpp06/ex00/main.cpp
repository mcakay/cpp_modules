#include "Cast.hpp"

int main(int argc, char *argv[])
{
	Error err;
	Cast cast;
	err.checkArguments(argc);
	err.checkInput(argv[1]);
	std::cout << argv[1] << std::endl;
	cast.castChar(argv[1], err);
	cast.castInt(argv[1], err);	
	cast.castFloat(argv[1], err);
	cast.castDouble(argv[1], err);
	return 0;
}
