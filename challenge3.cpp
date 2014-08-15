#include <iostream>
#include <string>

std::string encryptCeasarCypher(const std::string &input,int shift)
{
	std::string result;

	for(auto c : input)
	{
		result += c + shift;
	}

	return result;
}

std::string decryptCeasarCypher(const std::string &input, int shift)
{
	std::string result;

	for(auto c : input)
	{
		result += c - shift;
	}

	return result;
}

int main(int argc, char *argv[])
{
	std::string encrypted = encryptCeasarCypher(static_cast<std::string>("hallo"),3);
	std::cout<< encrypted <<std::endl;
	std::cout<< decryptCeasarCypher(encrypted,3) <<std::endl;
	return 0;
}