#include<iostream>
#include<fstream>
#include<string>
#include"rotorComprobation.h"
#include<Windows.h>
bool rotorAConfig()
{
	char notch='Z';
	system("cls");
	std::cout << "Rotor A configuration:\n";
	
	while (true)
	{
		
		
		if (GetAsyncKeyState(VK_ESCAPE) == -32767) //If key number 1 "1" is presed send user to messageEncrypt.cpp
		{
			return 0;
		}
			system("pause");
			system("cls");
			std::cout << "Starting configuration of rotor A...\nInsert the characters ordenation:";
			std::string rotorConfi;
			Sleep(100);
			if (rotorComprobation(rotorConfi, 'A', notch))
			{
				return 1;
			}
			
	
		
	}
	





}