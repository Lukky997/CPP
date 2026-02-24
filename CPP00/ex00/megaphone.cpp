#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string output;
	for(int i = 1; i < argc; ++i)
	{
		for(int len = 0; argv[i][len]; len++)
		{
			char c = toupper(argv[i][len]);
			output += c;
		}
		if (i != argc - 1)
			output += " ";
	}
	std::cout << output << std::endl;
	return (0);
}
