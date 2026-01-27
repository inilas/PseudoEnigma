#include<iostream>
#include<fstream>
#include<string>
void rotorComprobation(std::string rotorConfi,char letter)
{
	int count;
	std::cin.clear();
	getline(std::cin, rotorConfi);
	std::cout << rotorConfi.length();

	if (rotorConfi.length() != 26)
	{
		std::cout << "Error: Key must contain 26 characters.\n";
		return;
	}
	int l = rotorConfi.length();



	for (int i = 0; i < l; i++) 
	{
		count = 1; //Updates the count again to 1 for every new character

		for (int j = i + 1; j < l; j++)
		{
			if (rotorConfi[i] == rotorConfi[j] && rotorConfi[i] != ' ')
			{
				count++;
				//Set string[j] to 0 to avoid printing the visited character 
				rotorConfi[j] = '0';
			}
		}
		if (count > 1 && rotorConfi[i] != '0')
			std::cout << "Error: "<<rotorConfi[i]<<" its repited";
			
		return;
	}

	


	


	std::ofstream rotorABCConfi;
	rotorABCConfi.open("/Rotors/Rotor"+std::string(1,letter)+".txt");
	if (!rotorABCConfi.is_open())
	{
		std::cout << "Error: can't open /Rotors/Rotor" + std::string(1, letter) + ".txt";
		return;
	}
	else
	{
		std::cout << "Configuration completed!";
		return;
	}


}