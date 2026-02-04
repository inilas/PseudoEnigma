#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"getMessage.h"
bool rotorComprobation(std::string rotorConfi,char letter)
{
	int count;
	std::cin.clear();
	getline(std::cin, rotorConfi);
	std::string cleanedMessage=cleanMessage(rotorConfi);
//	std::cout << rotorConfi.length();

	if (cleanedMessage.length() != 26)
	{
		std::cout << "Error: Key must contain 26 characters.\n";
		return 0;
	}
	
	
	
	
	int l = cleanedMessage.length();

	for (int i = 0; i < l; i++) {
		if (cleanedMessage[i] == ' ' || cleanedMessage[i] == '0') continue;

		int count = 1;
		for (int j = i + 1; j < l; j++) {
			if (cleanedMessage[i] == cleanedMessage[j]) {
				count++;
				if (count > 1) {
					std::cout << "ERROR: '" << cleanedMessage[i] << "' repeated " << count << " times\n";
					return 0;  // Has duplicate
				}
			}
		}
	}
	
		


	std::ofstream rotorABCConfi;
	rotorABCConfi.open("Rotors/Rotor"+std::string(1,letter)+".txt");
	if (!rotorABCConfi.is_open())
	{
		std::cout << "Error: can't open /Rotors/Rotor" + std::string(1, letter) + ".txt\n";
		return 0;
	}
	else
	{
		rotorABCConfi << cleanedMessage;
		std::cout << "Configuration completed!";
		rotorABCConfi.close();
		Sleep(700);
		return 1;
	}


}