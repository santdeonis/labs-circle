#include <iostream>
#include<locale.h>  
#include<vector>  
#include"crcl.h"
int main()
{
	ccircle c1(2, 0, 1), c2(3, 1, 1), c3, c4;
	using namespace std;
	setlocale(LC_ALL, "RUS");
	std::cout << "������ ����������" << " c1:";
	c1.PrintInfo();
	std::cout << "������ ����������" << " c2:";
	c2.PrintInfo();
	std::cout << "���������������� �������� �3=�2-�1:";
	c3 = c2 - c1;
	c3.PrintInfo();
	c4 = -c3;
	std::cout << "������� �������� �4=-�3:";
	c4.PrintInfo();
	system("pause");

};
