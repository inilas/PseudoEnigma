#include<iostream>
#include"rotorABCConfig.h"
#include<Windows.h>
void rotorConfig()
{
	system("cls");
	char inputUser;
	std::cout << "rotor configuration\n";
	std::cout << "What rotor do you want to modify?\n";
	std::cout << "	1.Rotor A\n	2.Rotor B\n	3.Rotor C\n	4.Back";

	while (true)
	{
		if (GetAsyncKeyState(49) == -32767) //If key number 1 "1" is presed send user to messageEncrypt.cpp
		{
			if (rotorAConfig())
				return;
			
		}

		if (GetAsyncKeyState(50) == -32767) //If key number 2 "2" is presed send user to messageDecrypt.cpp
		{
			if (rotorBConfig())
				return;
			
		}
		if (GetAsyncKeyState(51) == -32767) //If key number 3 "3" is presed send user to rotorConfig.cpp
		{
			if (rotorCConfig())
				return;
		}
		if (GetAsyncKeyState(52) == -32767) //If key number 4 "4" is presed program ends
		{
			return;
		}

		Sleep(100);
	}
}


