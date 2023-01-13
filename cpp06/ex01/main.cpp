#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data* data = new Data;
	data->s = "Hello World!";
	uintptr_t raw = serialize(data);
	Data* data2 = deserialize(raw);
	std::cout << raw << std::endl;
	std::cout << data2->s << std::endl;
	std::cout << data << std::endl;
	delete data;	
	return 0;
}

