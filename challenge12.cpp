#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::string input;
	std::cin>>input;

	while(std::next_permutation(input.begin(),input.end()))
	{
		std::cout<<input<<std::endl;
	}

	return 0;
}