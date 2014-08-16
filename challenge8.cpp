//	ttp://www.reddit.com/r/dailyprogrammer/comments/pserp/2162012_challenge_8_easy/
#include <iostream>
#include <string>

void Sing()
{
	int bottles = 99;
	while(bottles > 0)
	{	

		if(bottles != 1)
		{
			std::cout<< bottles <<" bottles of beer on the wall," << bottles << " bottles of beer.\n";
			std::cout<< "Take one down and pass it around," << --bottles << " bottles of beer on the wall.\n"<<std::endl;
		}
		else 
		{
			std::cout<< bottles <<" bottle of beer on the wall," << bottles << " bottle of beer.\n";
			std::cout<<"Take one down and pass it around, no more bottles of beer on the wall.\n"<<std::endl;
			bottles--;
		}

	}
	std::cout<< "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall."<< std::endl;
}

int main(int argc, char const *argv[])
{
	Sing();
	return 0;
}