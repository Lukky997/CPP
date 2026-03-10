#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    private:
        std::string Name;
        int Hit = 10;
        int Energy = 10;
        int Attack = 10;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif