#include <iostream>
#include <string>
#include <fstream>

bool verifyFile(std::ifstream &file)
{
	if(file.is_open())
	{
		std::string verification;
		std::getline(file,verification);

		if(verification == "f7032aa15f5dc2d069d47cf403fa9790") //verification hash
		{
			return true;
		}
	}
	return false;
}

void getData(std::ifstream &file,std::string &username,std::string &password)
{
	int i = 1;
	for(std::string buffer; std::getline(file,buffer); i++)
	{
		if(i == 1)
		{
			username = buffer;
		}	
		if(i == 2)
		{
			password = buffer;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::string username, password,lUsername,lPassword;
	std::ifstream file("login.txt");
	
	std::getline(std::cin,username);
	std::getline(std::cin,password);

	if(verifyFile(file))
	{
		getData(file,lUsername,lPassword);
		if(lUsername == username && lPassword == password)
		{
			std::cout<<"Login succesfull!"<<std::endl;
		}
		else
		{
			std::cout<<"Login failed!"<<std::endl;
		}
	}

	return 0;
}