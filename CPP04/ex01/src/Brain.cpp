#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const {
	if (i >= 0 && i < 100)
		return(_ideas[i]);
	return("");
}

void Brain::setIdea(int i, const std::string& idea) {
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
}
