#include <iostream>
#include <fstream>
#include <string>

int check_files(std::string intputName, std::string outputName, std::ifstream *input, std::ofstream *output)
{
	if (intputName.empty() || outputName.empty())
		return (1);

	(*input).open(intputName.c_str());
	(*output).open(outputName.c_str());
	if (!input->is_open() || !output->is_open())
	{
		if (!input->is_open())
			std::cout << "Failed to open " << intputName << std::endl;
		if (!output->is_open())
			std::cout << "Cannot create output file" << std::endl;
		return (1);
	}
	return (0);
}

void replaceString(char **argv, std::ifstream *input, std::ofstream *output)
{
	std::string line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cout << "Error: string1 cannot be empty" << std::endl;
		return;
	}

	while(std::getline(*input, line))
	{
		std::string newLine;
		size_t pos = 0;

		while (pos < line.length())
		{
			size_t found = line.find(s1, pos);

			if (found != std::string::npos && found == pos)
			{
				newLine += s2;
				pos += s1.length();
			}
			else
			{
				newLine += line[pos];
				pos++;
			}
		}
		*output << newLine;
		if (!(*input).eof())
			*output << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Use: ./sed <filename> \"string1\" \"string2\"" << std::endl;
		return (0);
	}

	std::ifstream input;
	std::ofstream output;

	std::string outputName = std::string(argv[1]) + ".replace";
	
	if (check_files(argv[1], outputName, &input, &output))
		return (1);
	replaceString(argv, &input, &output);

	input.close();
	output.close();
	return (0);
}
