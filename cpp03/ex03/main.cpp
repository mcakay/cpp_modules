#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d("diamond");

	d.attack("Melih");
	d.takeDamage(6);
	d.beRepaired(4);
	d.takeDamage(3);
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();
	d.beRepaired(8);
	d.takeDamage(17);
	return (0);
}