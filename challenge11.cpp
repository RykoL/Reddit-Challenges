#include <cmath>
#include <iostream>

int toJulianMonth(int m)
{
	int months[] = {11,12,1,2,3,4,5,6,7,8,9,10};
	return months[m - 1];
}

std::string toText(int num)
{
	std::string day[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	return day[num];
}

std::string gaussian(int day,int month,int year) //using the gaussian formula
{
	if(day < 1 && day > 31) //check for invalid input
		return "";

	int d = day,m = toJulianMonth(month),y,c,w;

	if(m == 11 || m == 12)
		y = year % 100 - 1;
	else
		y = year % 100;

	if(m == 11 || m == 12)
		c = year / 100 - 1;
	else
		c = year / 100;
	
	w = (d + floor(2.6 * m - 0.2) + y + floor(y  / 4) + floor(c / 4) - 2 * c);
	w %= 7;
	return toText(w);
}


int main()
{
	int day = 24,month = 8,year = 2014;
	
	std::cout<<"Enter the day: ";
	std::cin>>day;

	std::cout<<"Enter the month: ";
	std::cin>>month;

	std::cout<<"Enter the year: ";
	std::cin>>year;
	
	std::cout<<gaussian(day, month , year)<<std::endl;

	return 0;
}