#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap *clapTrapHorde = new ClapTrap[3];
	ClapTrap target("Melih");
	for (int i = 0; i < 3; i++)
	{
		clapTrapHorde[i].attack(target.getName());
		target.takeDamage(clapTrapHorde[i].getAttackDamage());
	}
	delete [] clapTrapHorde;
	target.beRepaired(3);
	ScavTrap s;
	s.attack("Melih");
	s.beRepaired(10);
	s.guardGate();
	s.takeDamage(15);
	return (0);
}