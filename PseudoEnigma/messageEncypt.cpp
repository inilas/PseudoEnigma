#include<iostream>
#include<string>
#include"getMessage.h"
void messageEncrypt()
{
	system("cls");
	std::cout << "Encrypt section\n";
	
	mesageAnimation();

	std::cout << "Ready to encrypt!";
	std::cout << "What mesage do you want to encrypt?\n";
	std::string var1;
	std::cin.clear();
	getline(std::cin, var1);
	std::cout << cleanMessage(var1);
}