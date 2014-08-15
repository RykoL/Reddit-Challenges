#include <map>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

class Morse
{
public:
	Morse();
	std::string Decrypt(std::string morseStr);

private:
	std::map<std::string,std::string> Alphabet;
	void initializeMap(std::map<std::string,std::string> &map);
};

void Morse::initializeMap(std::map<std::string, std::string> &map)
{
	map[".-"] = "A";
	map["-..."] = "B";
	map["-.-."] = "C";
	map["-.."] = "D";
	map["."] = "E";
	map["..-."] = "F";
	map["--."] = "G";
	map["...."] = "H";
	map[".."] = "I";
	map[".---"] = "J";
	map["-.-"] = "K";
	map[".-.."] = "L";
	map["--"] = "M";
	map["-."] = "N";
	map["---"] = "O";
	map[".--."] = "P";
	map["--.-"] = "Q";
	map[".-."] = "R";
	map["..."] = "S";
	map["-"] = "T";
	map["..-"] = "U";
	map["...-"] = "V";
	map[".--"] = "W";
	map["-..-"] = "X";
	map["-.--"] = "Y";
	map["--.."] = "Z";
}

Morse::Morse()
{
	initializeMap(Alphabet);
}

std::string Morse::Decrypt(std::string morseStr)
{
	std::vector<std::string> words;
	std::vector<std::string> chars;
	std::string decrypted;

	boost::split(words,morseStr,boost::is_any_of("/"));

	for(auto x : words)
	{
		boost::split(chars,x,boost::is_any_of(" "));

		for(auto c :  chars)
		{
			decrypted += Alphabet[c];
		}
		decrypted += " ";
	}

	return decrypted;
}

int main(int argc, char const *argv[])
{
	std::string text = ".... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--";

	Morse morse;
	std::cout<< morse.Decrypt(text) << std::endl;

	return 0;
}