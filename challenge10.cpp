//Challenge 10 - http://www.reddit.com/r/dailyprogrammer/comments/pv98f/2182012_challenge_10_easy/
#include <iostream>
#include <boost/regex.hpp>
// [0-9]{10} matches 1234567890
// ([0-9]{3}-){2}[0-9]{4} matches 123-456-7890
// ([0-9]{3}\.){2}[0-9]{4} matches 123.456.7890 
// \([0-9]{3}\)[0-9]{3}-[0-9]{4}  matches (123)456-7890
// \([0-9]{3}\) [0-9]{3}-[0-9]{4} matches (123) 456-7890

class TelephonNumberValidator
{
public:
	bool Check(const std::string &number);
};

bool TelephonNumberValidator::Check(const std::string &number)
{
	std::string patterns[] = {R"([0-9]{10})", R"(([0-9]{3}-){2}[0-9]{4})", R"(([0-9]{3}\.){2}[0-9]{4})", R"(\([0-9]{3}\)[0-9]{3}-[0-9]{4})", R"(\([0-9]{3}\) [0-9]{3}-[0-9]{4})"};


	for(int i = 0; i < 5; i++)
	{
		if(boost::regex_match(number,boost::regex(patterns[i]))) //using boost::regex instead of std::regex, because gcc 4.8 has not fully implemented ECMAScript support
		{
			return true;
		}

	}
	return false;
}

int main(int argc, char const *argv[])
{
	TelephonNumberValidator numberValidator;
	std::string numbers[] = {"1234567890","123-456-7890","123.456.7890","(123)456-7890","(123) 456-7890"};

	for(int i = 0; i < 5; i++)
	{
		if( numberValidator.Check(numbers[i]) )
		{
			std::cout<< numbers[i] << " is a valid TelephonNumber. "<<std::endl;
		}
		else
			std::cout<< numbers[i] << " is not a valid TelephonNumber. "<<std::endl;
	}
	return 0;
}
