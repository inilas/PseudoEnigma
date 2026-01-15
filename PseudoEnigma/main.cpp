#include<iostream>
#include"mesageEncrypt.h"
#include"mesageUnEncrypt.h"
#include"rotorConfig.h"
#include<Windows.h>
int main()
{

	char inputUser;
	bool bucle = 1;
		std::cout <<"		==============================\n			ENIGMA MACHINE\n		==============================\n";
		std::cout << "			1. Encrypt Message\n\n			2. Decrypt Message\n\n			3. Configure Rotors\n\n			4. Exit\n";
		
		
		while (true)
		{
			for (inputUser = 0; inputUser < 255; inputUser++) //comprueba cada tecla todo el rato
			{
				if (GetAsyncKeyState(inputUser) == -32767) //si la tecla pasada por esta funcion da ese numero, significa que está precionada
				{
					if (inputUser==49)
					{
						mesageEncrypt();
					}
					else if (inputUser==50)
					{
						mesageUnEncrypt();
					}
					else if (inputUser==51)
					{
						rotorConfig();
					}
				}
			}
			std::cout << inputUser;
			Sleep(100);
		}





}

	