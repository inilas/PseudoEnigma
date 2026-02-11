#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>

void insertMessageTxt(std::string inputMessage) {

    std::ofstream messageFile;
    messageFile.open("Message.txt");

    if (messageFile.is_open()) {
        messageFile << inputMessage;
    }
    else
    {
        std::cout << "The original message hasn't been able to get saved.";
    }
    messageFile.close();
    
}



std::string cleanMessage (std::string rawMessage)
{   
    std::string cleanedMessage;
    for (int i = 0; i < rawMessage.length(); i++) {
        char c = rawMessage[i];

		switch (c) {
			case 'á': case 'à': c = 'a'; break;
			case 'é': case 'è': c = 'e'; break;
			case 'í': case 'ì': c = 'i'; break;
			case 'ó': case 'ò': c = 'o'; break;
			case 'ú': case 'ù': c = 'u'; break;
			case 'ñ': c = 'n'; break;

			case 'Á': case 'À': c = 'A'; break;
			case 'É': case 'È': c = 'E'; break;
			case 'Í': case 'Ì': c = 'I'; break;
			case 'Ó': case 'Ò': c = 'O'; break;
			case 'Ú': case 'Ù': c = 'U'; break;
			case 'Ñ': c = 'N'; break;
		}

        // Convertir manualmente a mayúscula
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');  
        }

        // Solo aceptar A-Z
        if (c >= 'A' && c <= 'Z') {
            cleanedMessage += c;
        }
    }

    return cleanedMessage;
}


char cleanNotch(char& notch)
{
	if (notch >= 'a' && notch <= 'z') {
		notch = notch - ('a' - 'A');
	}
	if (notch >= 'A' && notch <= 'Z') {
		return notch;
	}
	else
	{
		std::cout << "There's an error reading notch, try again.";
		system("pause");
	}
}

bool correctRotorOrdenation(std::string rotorOrdenation)
{
	short stringLenght = rotorOrdenation.length();

	
	if (stringLenght !=3)
	{
		std::cout << "You must introduce 3 letters\n";
		system("pause");
		return 1;
	}
	for (int i = 0; i < stringLenght; i++) 
	{
		if (rotorOrdenation[i]!='A' && rotorOrdenation[i]!='B' && rotorOrdenation[i]!='C')
		{
			std::cout << "There's not a rotor \"" << rotorOrdenation[i] << "\", try again\n";
			system("pause");
			return 1;
		}
		for (int j = i + 1; j < stringLenght; j++) 
		{
			if (rotorOrdenation[i] == rotorOrdenation[j]) {
				std::cout << "There is repeated characters\n";
				system("pause");
				return 1;
			}
		}
	}
	return 0;
}

void mesageAnimation(std::string rotorOrdenation)
{
	for (short i = 0; i < rotorOrdenation.length(); i++)
	{
		if (rotorOrdenation[i] == 'A')
		{
			std::cout << "Preparing rotor A";
			Sleep(200);
			std::cout << ".";
			Sleep(400);
			std::cout << ".";
			Sleep(200);
			std::cout << ".";
			std::cout << " Rotor A ready!\n";
		}

		if (rotorOrdenation[i] == 'B')
		{
			std::cout << "Preparing rotor B";
			Sleep(200);
			std::cout << ".";
			Sleep(400);
			std::cout << ".";
			Sleep(200);
			std::cout << ".";
			std::cout << " Rotor B ready!\n";
		}


		if (rotorOrdenation[i] == 'C')
		{
			std::cout << "Preparing rotor C";
			Sleep(200);
			std::cout << ".";
			Sleep(400);
			std::cout << ".";
			Sleep(200);
			std::cout << ".";
			std::cout << " Rotor C ready!\n";
		}
	}	
	system("pause");
}