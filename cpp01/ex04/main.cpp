#include <iostream>
#include <fstream>

int error(std::string fileName, std::string search, std::string replace)
{
	if (fileName.empty() || search.empty() || replace.empty())
	{
		std::cout << "Arguments cannot be empty" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./program [fileName] [search] [replace]" << std::endl;
		return (1);
	}
	std::string fileName = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	std::string line;
	size_t pos = 0;
	if (error(fileName, search, replace))
		return (2);
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return (3);
	}
	std::ofstream newFile(fileName + ".replace", std::ios::trunc);
	if (!newFile.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return (4);
	}
	while (std::getline(file, line))
	{
		pos = 0;
		while ((pos = line.find(search, pos)) != std::string::npos)
		{
			line.erase(pos, search.length());
			line.insert(pos, replace);
		}
		newFile << line << std::endl;
	}
	return (0);
}