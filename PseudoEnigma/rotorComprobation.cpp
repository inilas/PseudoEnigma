#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
bool rotorComprobation(std::string rotorConfi,char letter)
{
	int count;
	std::cin.clear();
	getline(std::cin, rotorConfi);
//	std::cout << rotorConfi.length();

	if (rotorConfi.length() != 26)
	{
		std::cout << "Error: Key must contain 26 characters.\n";
		return 0;
	}
	
	
	
	
	int l = rotorConfi.length();

	for (int i = 0; i < l; i++) {
		if (rotorConfi[i] == ' ' || rotorConfi[i] == '0') continue;

		int count = 1;
		for (int j = i + 1; j < l; j++) {
			if (rotorConfi[i] == rotorConfi[j]) {
				count++;
				if (count > 1) {
					std::cout << "ERROR: '" << rotorConfi[i] << "' repeated " << count << " times\n";
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
		std::cout << "Configuration completed!";
		Sleep(700);
		return 1;
	}


}