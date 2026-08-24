#include "RPN.hpp"

Rpn::Rpn() {
}

Rpn::Rpn(Rpn const &copy) {
	_stack = copy._stack;
}

Rpn &Rpn::operator=(Rpn const &copy) {
	if (this != &copy) 
		_stack = copy._stack;

	return *this;
}

Rpn::~Rpn() {
}

void Rpn::calcul(std::string const &expression) {
    std::stringstream   ss(expression);
    std::string         token;

    while (ss >> token) {

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                std::cerr << "Error" << "\n";
                return ;
            }
            long b = _stack.top(); _stack.pop();
            long a = _stack.top(); _stack.pop();

            if (token == "+")
				_stack.push(a + b);
            if (token == "-")
				_stack.push(a - b);
            if (token == "*")
				_stack.push(a * b);
            if (token == "/") {
                if (b == 0) {
                    std::cerr << "Error: division by zero" << "\n";
                    return ;
                }
                _stack.push(a / b);
            }
        }
		else {
            if (token.length() != 1 || token[0] < '0' || token[0] > '9') {
				std::cerr << "Error" << "\n";
				return ;
			}

            _stack.push(token[0] - '0');
		}
    }
    if (_stack.size() != 1) {
        std::cerr << "Error" << "\n";
        return ;
    }
    std::cout << _stack.top() << "\n";
}