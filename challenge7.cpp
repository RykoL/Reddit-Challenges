#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <boost/algorithm/string.hpp>

class Morse
{
public:
	Morse();
	std::string Decrypt(std::string &morseStr);
	std::string Encrypt(std::string &str);

private:
	std::map<std::string,std::string> MorseAlphabet;
	std::map<char ,std::string> Alphabet;
	void initializeMap();
};

void Morse::initializeMap()
{
	MorseAlphabet[".-"] = "A";
	MorseAlphabet["-..."] = "B";
	MorseAlphabet["-.-."] = "C";
	MorseAlphabet["-.."] = "D";
	MorseAlphabet["."] = "E";
	MorseAlphabet["..-."] = "F";
	MorseAlphabet["--."] = "G";
	MorseAlphabet["...."] = "H";
	MorseAlphabet[".."] = "I";
	MorseAlphabet[".---"] = "J";
	MorseAlphabet["-.-"] = "K";
	MorseAlphabet[".-.."] = "L";
	MorseAlphabet["--"] = "M";
	MorseAlphabet["-."] = "N";
	MorseAlphabet["---"] = "O";
	MorseAlphabet[".--."] = "P";
	MorseAlphabet["--.-"] = "Q";
	MorseAlphabet[".-."] = "R";
	MorseAlphabet["..."] = "S";
	MorseAlphabet["-"] = "T";
	MorseAlphabet["..-"] = "U";
	MorseAlphabet["...-"] = "V";
	MorseAlphabet[".--"] = "W";
	MorseAlphabet["-..-"] = "X";
	MorseAlphabet["-.--"] = "Y";
	MorseAlphabet["--.."] = "Z";

	Alphabet['A'] = ".-";
	Alphabet['B'] = "-...";
	Alphabet['C'] = "-.-.";
	Alphabet['D'] = "-..";
	Alphabet['E'] = ".";
	Alphabet['F'] = "..-.";
	Alphabet['G'] = "--.";
	Alphabet['H'] = "....";
	Alphabet['I'] = "..";
	Alphabet['J'] = ".---";
	Alphabet['K'] = "-.-";
	Alphabet['L'] = ".-..";
	Alphabet['M'] = "--";
	Alphabet['N'] = "-.";
	Alphabet['O'] = "---";
	Alphabet['P'] = ".--.";
	Alphabet['Q'] = "--.-";
	Alphabet['R'] = ".-.";
	Alphabet['S'] = "...";
	Alphabet['T'] = "-";
	Alphabet['U'] = "..-";
	Alphabet['V'] = "...-";
	Alphabet['W'] = ".--";
	Alphabet['X'] = "-..-";
	Alphabet['Y'] = "-.--";
	Alphabet['Z'] = "--..";
}

Morse::Morse()
{
	initializeMap();
}

std::string Morse::Decrypt(std::string &morseStr)
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
			decrypted += MorseAlphabet[c];
		}
		decrypted += " ";
	}

	return decrypted;
}

std::string Morse::Encrypt(std::string &str)
{
	std::vector<std::string> words;
	std::vector<std::string> chars;
	std::string encrypted;
	
	boost::to_upper(str);
	boost::split(words,str,boost::is_any_of(" "));

	for(std::string s : words)
	{
		for(char c : s)
		{
			encrypted += Alphabet[c] + " ";
		}
		encrypted += "/ ";
	}

	return encrypted;
}

int main(int argc, char const *argv[])
{
	std::string text = ".... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--";
	std::string text2 = "HELLO DAILY PROGRAMMER GOOD LUCK ON THE CHALLENGES TODAY ";

	Morse morse;
	std::cout<< morse.Decrypt(text) << std::endl;
	std::cout<< morse.Encrypt(text2) << std::endl;

	return 0;
}