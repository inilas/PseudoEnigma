#include<iostream>
#include"mesageEncrypt.h"
#include"mesageUnEncrypt.h"
#include"rotorConfig.h"
int main()
{
	short inputUser;
	bool bucle = 1;
	while (bucle)
	{
		std::cout <<"		==============================\n			ENIGMA MACHINE\n		==============================\n";
		std::cout << "			1. Encrypt Message\n\n			2. Decrypt Message\n\n			3. Configure Rotors\n\n			4. Exit\n";
		
		std::cin >> inputUser;

		switch (inputUser)
		{
		case 1:
			mesageEncrypt();

			break;
		case 2:
			mesageUnEncrypt();

			break;
		case 3:
			rotorConfig();

			break;
		case 4:
			return 1;
			break;
		default:
			std::cout<<"There was a error, try tiping \"1\",\"2\",\"3\" or \"4\"\n";
			system("pause");
			system("cls");
			continue;
		}
	}

}	