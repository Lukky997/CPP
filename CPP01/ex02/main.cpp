#include <iostream>
#include <string>

int main()
{
	std::string hisThisBrain = "HI THIS IS BRAIN";
	std::string* stringPTR = &hisThisBrain;
	std::string& stringREF = hisThisBrain;

	std::cout << "Memory adress of string variable : " << &hisThisBrain << std::endl;
	std::cout << "Memory adress held by stringPTR  : " << stringPTR << std::endl;
	std::cout << "Memory adress held by stringREF  : " << &stringREF << std::endl;
	std::cout << "=================================================" << std::endl;
	std::cout << "Value of string variable      : " << hisThisBrain << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;

	return(0);
}