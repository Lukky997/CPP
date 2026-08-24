#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <sstream>

class Rpn {
    private:
        std::stack<long, std::list<long> > _stack;

    public:
        Rpn();
        Rpn(Rpn const &copy);
        Rpn &operator=(Rpn const &copy);
        ~Rpn();

        void calcul(std::string const &expression);
};

#endif