#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string name,username;
	int age;
	std::cout<<"Enter you Name: ";
	std::cin>>name;

	std::cout<<"Enter your Age: ";
	std::cin>>age;

	std::cout<<"Enter your reddit username: ";
	std::cin>>username;

	std::cout<<"Your name is " << name << ",you are "<< age
	<< " years old" << ", and your username is " << username << std::endl;

	std::cout<<"You data will be stored in data.txt"<<std::endl;

	std::ofstream of("data.txt");
	of<< name << " " << age << " " << username <<std::endl;
	of.close();
	
	return 0;
}