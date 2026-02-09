#include<iostream>
#include<string>
#include"getMessage.h"
#include<fstream>

void getRotorConf(std::string& wiring, char& notch, short i, std::string rotorOrdenation)
{
	std::ifstream rotorFile;
	std::string fileName = "Rotors/Rotor" + std::string(1, rotorOrdenation[i]) + ".txt";
	rotorFile.open(fileName);

	std::cout << "Geting " << fileName <<" data\n";
	if (!rotorFile.is_open())
	{
		std::cout << "Critical error, can't open " << fileName;
	}

	std::getline(rotorFile, wiring);
	std::string notchLetter;
	std::getline(rotorFile, notchLetter);
	rotorFile.close();
	notch = notchLetter[0];
}

void messageEncrypt()
{
	//var1 is equal to the string we going to encrypt

	bool rotorOrdenationIsCorrect = 1;
	std::string rotorOrdenation;
	system("cls");
	std::cout << "Encrypt section\n";
	system("pause");
	while (rotorOrdenationIsCorrect)
	{
		system("cls");
		std::cout << "Set rotor ordenation:\n";
		std::getline(std::cin, rotorOrdenation);
		rotorOrdenation = cleanMessage(rotorOrdenation);
		rotorOrdenationIsCorrect = correctRotorOrdenation(rotorOrdenation);
	}

	mesageAnimation(rotorOrdenation);

	system("cls");
	std::cout << "Ready to encrypt!\n";
	std::cout << "What mesage do you want to encrypt?\n";

	std::string var1;
	std::cin.clear();
	getline(std::cin, var1);
	var1 = cleanMessage(var1);
	








	//Encrypting====================================================

	char notch[3];
	std::string wiring[3];
	short id_leters[100];


	for (short i = 0; i < rotorOrdenation.length(); i++)
	{
		getRotorConf(wiring[i], notch[i], i, rotorOrdenation);
	}
	
	


	
//First rotor
//Starting values of id_leters
	for (short i = 0; i < var1.length(); i++)
	{
		for (short j = 0; j < wiring[0].length(); j++)
		{
			if (wiring[0][j] == var1[i])
			{
				id_leters[i] = j;
			}
		}
	}
//========================================================================

	for (short k = 0; k < rotorOrdenation.length(); k++)
	{
		for (short i = 0; i < var1.length(); i++)
		{
			if (var1[i] == notch[k])
			{
				var1[i] = wiring[k][id_leters[i]];

				for (short g = 0; g < var1.length(); g++)
				{
					id_leters[g] = id_leters[g] + 1;
				}
			}
			else
				var1[i] = wiring[k][id_leters[i]];
		}

		std::cout << var1 << "\n";

		for (short i = 0; i < var1.length(); i++)
		{
			for (short j = 0; j < wiring[k].length(); j++)
			{
				if (wiring[k][j] == var1[i])
				{
					id_leters[i] = j;
				}
			}
		}
	}


	std::ofstream cypherMessage("Message/xifrat.txt", std::ios::app);
	for (size_t i = 1; i < var1.length(); i++)
	{
		if (i%5==0)
		{
			cypherMessage << var1[i-1] << " ";
		}
		else
		{
			cypherMessage << var1[i-1];
		}

	}
	cypherMessage << "\n";
	cypherMessage.close();

	std::cout << var1 << "\n";
	system("pause");
}
		



	

	






	



