#include "phonebook.hpp"

int main(void)
{
	std::string 	input;
	int 		index = 0;
	Phonebook phonebook;

	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
		{
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			std::cout << "Enter first name: ";
			std::getline(std::cin, firstName);
			if (firstName == "")
			{
				std::cout << "First name cannot be empty" << std::endl;
				continue;
			}
			contact.setFirstName(firstName);
			std::cout << "Enter last name: ";
			std::getline(std::cin, lastName);
			if (lastName == "")
			{
				std::cout << "Last name cannot be empty" << std::endl;
				continue;
			}
			contact.setLastName(lastName);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			if (nickname == "")
			{
				std::cout << "Nickname cannot be empty" << std::endl;
				continue;
			}
			contact.setNickname(nickname);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phoneNumber);
			if (phoneNumber == "")
			{
				std::cout << "Phone number cannot be empty" << std::endl;
				continue;
			}
			contact.setPhoneNumber(phoneNumber);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);
			if (darkestSecret == "")
			{
				std::cout << "Darkest secret cannot be empty" << std::endl;
				continue;
			}
			contact.setDarkestSecret(darkestSecret);
			phonebook.addContact(contact, index);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (input == "SEARCH")
		{
			phonebook.printContacts();
			if (phonebook.isEmpty(0) == true)
				continue;
			std::cout << "Enter id of contact: ";
			std::getline(std::cin, input);
			if (input == "")
			{
				std::cout << "Id cannot be empty" << std::endl;
				continue;
			}
			if (isdigit(input[0]) == false)
			{
				std::cout << "Id must be a number" << std::endl;
				continue;
			}
			if (std::stoi (input) < 1 || std::stoi (input) > 8)
			{
				std::cout << "Id must be between 1 and 8" << std::endl;
				continue;
			}
			phonebook.printContact(std::stoi(input) - 1);
		}
	}

}
