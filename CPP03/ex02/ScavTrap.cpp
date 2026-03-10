#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap() {
	_name = "Pipi";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap constructor "<< _name << " called" << std::endl;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap constructor "<< _name << " called" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy " << _name << " constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "ScavTrap copy " << _name << " assignment operator called" << std::endl;
	if (this != &copy) {
		ClapTrap::operator=(copy);
	}

	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor "<< _name << " called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no energy points left." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -=1;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode !" << std::endl;
}