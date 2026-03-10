#include "includes/FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap() {
	_name = "Prout";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "FragTrap constructor "<< _name << " called" << std::endl;
}

FragTrap::FragTrap (std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "FragTrap constructor "<< _name << " called" << std::endl;
}

FragTrap::FragTrap (const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy " << _name << " constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& copy) {
	std::cout << "FragTrap copy " << _name << " assignment operator called" << std::endl;
	if (this != &copy) {
		ClapTrap::operator=(copy);
	}

	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor "<< _name << " called" << std::endl;
}


void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}