#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"


int	main(void) {

	ClapTrap	Clap;
	ClapTrap	Clap2("Zombie");

	ScavTrap	Scav;
	ScavTrap	Scav2("Skeleton");

	FragTrap frag;
    FragTrap frag2("Creeper");

	Clap.attack("Zombie");
	Clap.takeDamage(5);
	Clap.beRepaired(40);

	Scav.attack("Skeleton");
	Scav.takeDamage(30);
	Scav.beRepaired(60);
	Scav.guardGate();

	frag.attack("Boomer");
    frag.takeDamage(15);
    frag.beRepaired(10);
    frag.highFivesGuys();

	return (0);
}
