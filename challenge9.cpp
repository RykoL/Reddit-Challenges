//Challenge 9 - http://www.reddit.com/r/dailyprogrammer/comments/pu1rf/2172012_challenge_9_easy/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::vector<int> digits;
	std::string input;
	std::string temp;

	std::cout<< ">> ";
	std::cin >> input;

	for(char c : input)
	{
		if(std::isdigit(c) != 0)
		{
			temp = c;
			digits.push_back(std::stoi(temp));
		}
	}

	std::sort(digits.begin(), digits.end(),std::less<int>());

	for(int digit : digits)
	{
		std::cout<< digit <<std::endl;
	}
	return 0;
}