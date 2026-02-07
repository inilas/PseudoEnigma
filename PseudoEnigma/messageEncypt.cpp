#include<iostream>
#include<string>
#include"getMessage.h"
#include<fstream>

void getRotorConf(std::string& wiring, char& notch, short i, std::string rotorOrdenation)
{
	std::ifstream rotorFile;
	rotorFile.open("Rotors/Rotor" + std::string(1, rotorOrdenation[i]) + ".txt");

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

	std::cout << "Ready to encrypt!\n";
	std::cout << "What mesage do you want to encrypt?\n";

	std::string var1;
	std::cin.clear();
	getline(std::cin, var1);
	var1 = cleanMessage(var1);
	std::cout << var1;


	//Encrypting


	char notch[3];
	std::string wiring[3];
	short id_leters[100];
	std::string var_temp=var1;

	for (short i = 0; i < rotorOrdenation.length(); i++)
	{
		getRotorConf(wiring[i], notch[i], i, rotorOrdenation);
	}

	for (short i = 0; i < var1.length(); i++)
	{
		for (short j = 0; j < wiring[0].length(); j++) 
		{
			if (wiring[0][j] == var1[i]) {
				id_leters[i] = j;  
				break;
			}
		}
	}

	for (short i = 0; i < var1.length(); i++)
	{
		var_temp[i] = wiring[1][id_leters[i]];
	}

	for (short i = 0; i < var1.length(); i++)
	{
		var_temp[i] = wiring[2][id_leters[i]];
	}
	std::cout << var_temp;
}


	



