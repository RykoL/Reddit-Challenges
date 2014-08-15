#include <iostream>

double getAmperage(double U, double R)
{
	return U  / R;
}

double getVoltage(double R, double I)
{
	return R * I;
}

double getResistance(double U, double I) 
{
	return U / I;
}

int main(int argc, char const *argv[])
{
	int choice;
	double R,U,I;

	std::cout<<"You have following choices: \n"
	<<"1) calculate amperage \n"
	<<"2) calculate voltage \n"
	<<"3) calculate resistance\n\n"
	<<"Enter your Choice: ";
	
	while(std::cin>>choice)
	{	
		switch(choice)
		{
			case 1:
		{
				std::cout<<"enter voltage: ";
				std::cin>>U;

				std::cout<<"enter resistance: ";
				std::cin>>R;

				std::cout<<getAmperage(U,R)<<std::endl;
				break;
			}

			case 2:
			{
				std::cout<<"enter resistance: ";
				std::cin>>R;

				std::cout<<"enter amperage: ";
				std::cin>>I;

				std::cout<<getVoltage(R,I)<<std::endl;
				break;
			}

			case 3:
			{
				std::cout<<"enter voltage: ";
				std::cin>>U;

				std::cout<<"enter amperage: ";
				std::cin>>I;

				std::cout<<getResistance(U,I)<<std::endl;
				break;
			}
		}
	}

	return 0;
}