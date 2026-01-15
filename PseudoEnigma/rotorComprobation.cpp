#include<iostream>
#include<fstream>
void rotorComprobation(std::string rotorConfi,char letter)
{
	if (rotorConfi.length() != 25)
	{
		std::cout << "Error: there's no all the alphabetic letters";
		return;
	}
	else
	{
		for (short i = 0; i < rotorConfi.length(); i++)
		{
			for (short j = 0; j < rotorConfi.length(); j++)
			{
				if (i != j)
				{
					if (rotorConfi[i] != rotorConfi[j])
					{
						std::cout << "Error: theres a duplicate letter";
						return;
					}
				}

			}
		}
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