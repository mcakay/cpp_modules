#include "phonebook.hpp"

void	Phonebook::addContact(Contact contact, int index)
{
	this->contacts[index] = contact;
}

void	Phonebook::printContacts(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;

	std::cout << " |   Index  |First Name| LastName | Nickname |" << std::endl;
	std::cout << " |----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->isEmpty(i))
		{
			firstName = this->contacts[i].getFirstName();
			lastName = this->contacts[i].getLastName();
			nickname = this->contacts[i].getNickname();
			std::cout << " |" << std::setw(10) << i + 1 << "|";
			if (firstName.length() > 10)
				std::cout << firstName.substr(0, 9) << "." << "|";
			else
				std::cout << std::setw(10) << firstName << "|";
			if (lastName.length() > 10)
				std::cout << lastName.substr(0, 9) << "." << "|";
			else
				std::cout << std::setw(10) << lastName << "|";
			if (nickname.length() > 10)
				std::cout << nickname.substr(0, 9) << "." << "|";
			else
				std::cout << std::setw(10) << nickname << "| ";
			std::cout << std::endl;
		}
	}
	std::cout << " |----------|----------|----------|----------|" << std::endl;
}

void	Phonebook::printContact(int index)
{
	std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

bool	Phonebook::isEmpty(int index)
{
	if (this->contacts[index].getFirstName() != "")
		return (false);
	return (true);
}
