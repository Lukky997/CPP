#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
	int value;
	std::string name;

	Data(int v, std::string s) : value(v), name(s) {
	}

	Data() : value(0), name("default") {
	}
};

#endif