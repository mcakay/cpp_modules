#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap s;
	s.attack("Melih");
	s.beRepaired(10);
	s.guardGate();
	s.takeDamage(15);
	return (0);
}