#include<iostream>
#include<string>
#include"getMessage.h"
#include<Windows.h>
void mesageDecrypt()
{
	std::string rotorOrdenation;
	system("cls");
	std::cout << "Decrypt section:\n";

	mesageAnimation(rotorOrdenation);

	std::cout << "Ready to Decrypt!\n";
	std::cout << "What mesage do you want to Decrypt?\n";
	std::string var1;
	std::cin.clear();
	getline(std::cin, var1);
	std::cout << cleanMessage(var1);
	
}