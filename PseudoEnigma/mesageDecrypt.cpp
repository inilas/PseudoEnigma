#include<iostream>
#include<string>
#include"getMessage.h"
void mesageDecrypt()
{
	system("cls");
	std::cout << "What mesage do you want to UNencript?";
	std::string var1;
	std::cin.clear();
	getline(std::cin, var1);
	std::cout << cleanMessage(var1);
}