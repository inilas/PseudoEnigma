#include<iostream>
#include<fstream>
#include<string>
#include"rotorComprobation.h"
#include<Windows.h>
void rotorAConfig()
{
	while (true)
	{
		system("cls");
		std::cout << "Rotor A configuration:\nPress \"Esc\" to exit";
		std::string rotorConfi;

		if (GetAsyncKeyState(VK_ESCAPE) == -32767) //If key number 1 "1" is presed send user to messageEncrypt.cpp
		{
			return;
		}

		getline(std::cin, rotorConfi);
		std::cout << rotorConfi.length();


		rotorComprobation(rotorConfi, 'A');

	}
	





}