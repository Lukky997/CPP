#include "includes/ClapTrap.hpp"


int main()
{
    ClapTrap Clap;
    ClapTrap b("Skeleton");

    Clap.attack("Skeleton");
    b.takeDamage(3);
    b.beRepaired(2);

    return 0;
}