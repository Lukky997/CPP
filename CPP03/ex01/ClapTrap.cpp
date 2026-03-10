#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Caca"), _hitPoints(10),
	_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor "<< this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor "<< this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "Claptrap copy " << this->_name << " constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "Claptrap copy " << this->_name << " assignment operator called" << std::endl;
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap () {
	std::cout << "ClapTrap destructor "<< this->_name << " called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy points left." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target
        << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -=1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;

	if (amount >= (unsigned int)_hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " can't repair itself." << std::endl;
		return;
	}

	std::cout << "ClapTrap " << _name << " repairs itself and recovers " << amount
		<< " hit points." << std::endl;
	_hitPoints += amount;
	_energyPoints -= 1;
}