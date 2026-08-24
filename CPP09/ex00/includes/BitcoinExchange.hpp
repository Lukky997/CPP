#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

class BitcoinExchange {
	private:
		std::map<std::string, float> _db;
		bool	isValidDate(std::string const &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);
		~BitcoinExchange();

		void	loadDatabase(std::string const &filename);
		void	processInput(std::string const &filename);
		float	getPriceForDate(std::string const &date) const;
};

#endif