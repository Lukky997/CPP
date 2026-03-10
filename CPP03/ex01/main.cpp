#include "includes/ScavTrap.hpp"


int	main(void) {

	ClapTrap	Clap;
	ClapTrap	Clap2("Zombie");
	ScavTrap	Scav;
	ScavTrap	Scav2("Skeleton");

	Clap.attack("Zombie");
	Clap.takeDamage(5);
	Clap.beRepaired(40);

	Scav.attack("Skeleton");
	Scav.takeDamage(30);
	Scav.beRepaired(60);
	Scav.guardGate();
	
	return (0);
}