#include<iostream>
#include<string>
#include"getMessage.h"
#include<fstream>

void getRotorConf(std::string& wiring, char& notch, short i, std::string rotorOrdenation)
{
	std::ifstream rotorFile;
	std::string fileName = "Rotors/Rotor" + std::string(1, rotorOrdenation[i]) + ".txt";
	rotorFile.open(fileName);


	std::cout << fileName << "\n";


	if (!rotorFile.is_open())
	{
		std::cout << "Critical error, can't open " << fileName;
	}

	std::getline(rotorFile, wiring);
	std::string notchLetter;
	std::getline(rotorFile, notchLetter);
	rotorFile.close();
	std::cout << rotorFile.is_open();
	notch = notchLetter[0];

	std::cout << wiring<<"\n";
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
	





	//Encrypting
	char notch[3];
	std::string wiring[3];
	short id_leters[1000];
	std::string var_temp=var1;

	for (short i = 0; i < rotorOrdenation.length(); i++)
	{
		getRotorConf(wiring[i], notch[i], i, rotorOrdenation);
	}
	
	


	
//First rotor


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

	for (short i = 0; i < var1.length(); i++)
	{
		if (var1[i] == notch[0])
		{
			var_temp[i] = wiring[0][id_leters[0]];

			for (short g = 0; g < var1.length(); g++)
			{
				id_leters[g] = id_leters[g] + 1;
			}
		}
		else
			var_temp[i] = wiring[0][id_leters[i]];
	}


	//Second rotor


		for (short i = 0; i < var1.length(); i++)
	{
		if (var_temp[i] == notch[1])
		{
			var_temp[i] = wiring[1][id_leters[i]];

			for (short g = 0; g < var1.length(); g++)
			{
				id_leters[g] = id_leters[g] + 1;
			}
		}
		else
			var_temp[i] = wiring[1][id_leters[i]];
	}	

//Thith rotor

	for (short i = 0; i < var1.length(); i++)
	{
		if (var_temp[i] == notch[2])
		{
			var_temp[i] = wiring[2][id_leters[i]];

			for (short g = 0; g < var1.length(); g++)
			{
				id_leters[g] = id_leters[g] + 1;
			}
		}
		else
			var_temp[i] = wiring[2][id_leters[i]];
	}


		
	std::ofstream cypherMessage;

	std::ofstream cypherMessage("Message/xifrat.txt", std::ios::app);
	cypherMessage << var_temp << std::endl;


	cypherMessage.close();

	std::cout << var_temp;
	system("pause");
}
		



	

	






	



