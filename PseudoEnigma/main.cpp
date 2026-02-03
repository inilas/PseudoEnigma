#include<iostream>
#include"mesageEncrypt.h"
#include"mesageUnEncrypt.h"
#include"rotorConfig.h"
#include "getMessage.h"
#include<Windows.h>
int main()
{

	char inputUser;
	bool bucle = 1;

	while (true)
	{
		system("cls");
		std::cout << "		==============================\n			ENIGMA MACHINE\n		==============================\n";
		std::cout << "			1. Encrypt Message\n\n			2. Decrypt Message\n\n			3. Configure Rotors\n\n			4. Exit\n";


		while (bucle)
		{
			
			if (GetAsyncKeyState(49) == -32767) //If key number 1 "1" is presed send user to messageEncrypt.cpp
			{
				std::cout << "Insert a message to cypher: ";
				std::cout << getMessage();
				messageEncrypt(); //going to messageEncrypt.cpp
				break;
			}

			if (GetAsyncKeyState(50) == -32767) //If key number 2 "2" is presed send user to messageDecrypt.cpp
			{
				std::cout << "Insert a message to decypher: ";
				std::cout << getMessage();
				mesageDecrypt(); //going to messageDecrypt.cpp
				break;
			}
			if (GetAsyncKeyState(51) == -32767) //If key number 3 "3" is presed send user to rotorConfig.cpp
			{
				rotorConfig(); //going to rotorConfig.cpp
				break;
			}
			if (GetAsyncKeyState(52) == -32767) //If key number 4 "4" is presed program ends
			{
				return 1;
			}

			Sleep(100);
		}
	}
		


		return 0;


}

	