#include<iostream>
#include<fstream>
#include<string>
#include"rotorComprobation.h"
#include<Windows.h>
void rotorAConfig()
{
	system("cls");
	std::cout << "Rotor A configuration:\nPress \"Esc\" to exit or ";
	while (true)
	{
		
		
		if (GetAsyncKeyState(VK_ESCAPE) == -32767) //If key number 1 "1" is presed send user to messageEncrypt.cpp
		{
			return;
		}
			system("pause");
			std::cout << "Starting configuration...\nInsert the characters ordenation:";
			std::string rotorConfi;
			Sleep(100);
			rotorComprobation(rotorConfi, 'A');

	
		
	}
	





}