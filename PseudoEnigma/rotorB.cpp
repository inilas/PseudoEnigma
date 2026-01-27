#include<iostream>
#include<fstream>
#include<string>
#include"rotorComprobation.h"
#include<Windows.h>

bool rotorBConfig()
{
	system("cls");
	std::cout << "Rotor B configuration:\nPress \"Esc\"\n";

	while (true)
	{


		if (GetAsyncKeyState(VK_ESCAPE) == -32767) //If key number 1 "1" is presed send user to messageEncrypt.cpp
		{
			return 0;
		}
		system("pause");
		system("cls");
		std::cout << "Starting configuration of rotor B...\nInsert the characters ordenation:";
		std::string rotorConfi;
		Sleep(100);
		if (rotorComprobation(rotorConfi, 'B'))
		{
			return 1;
		}



	}
}