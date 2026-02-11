#include<iostream>
#include<string>
#include"getMessage.h"
#include "rotorConfig.h"
#include<Windows.h>
void mesageDecrypt()
{
    system("cls");
    std::cout << "Decrypt section:\n";


    std::cout << "Ready to Decrypt!\n";
    std::cout << "What mesage do you want to Decrypt?\n";
    std::string var1;
    std::cin.clear();
    getline(std::cin, var1);
    std::cout << cleanMessage(var1);

    system("cls");
    std::cout << "Decrypt section\n";
    system("pause");

    // 1 Pedir orden de rotores
    std::string rotorOrdenation;
    bool rotorOrdenationIsCorrect = true;

    while (rotorOrdenationIsCorrect)
    {
        system("cls");
        std::cout << "Set rotor ordenation:\n";
        std::getline(std::cin, rotorOrdenation);
        rotorOrdenation = cleanMessage(rotorOrdenation);
        rotorOrdenationIsCorrect = correctRotorOrdenation(rotorOrdenation);
    }
    mesageAnimation(rotorOrdenation);

    // 2 Cargar rotores
    char notch[3] = {};
    std::string wiring[3];

    for (short i = 0; i < rotorOrdenation.length(); i++)
    {
        getRotorConf(wiring[i], notch[i], i, rotorOrdenation);
    }

    short id_leters[100] = {};
    // 4 DESCIFRADO (rotores AL REVÉS)
    for (int k = rotorOrdenation.length() - 1; k >= 0; k--)
    {
        

        // Paso A: letra índice (inline)
        for (int i = 0; i < var1.length(); i++)
        {
            for (int j = 0; j < wiring[k].length(); j++)
            {
                if (wiring[k][j] == var1[i])
                {
                    id_leters[i] = j;
                    break;
                }
            }
        }


        // Paso B: deshacer notch
        for (int i = 0; i < var1.length(); i++)
        {
            if (var1[i] == notch[k])
            {
                for (int g = 0; g < var1.length(); g++)
                {
                    id_leters[g]--;
                    if (id_leters[g] < 0)
                        id_leters[g] += 26; // wrap-around
                }
            }
        }


        // Paso C: índice letra
        for (int i = 0; i < var1.length(); i++)
        {
            var1[i] = 'A' + id_leters[i];
        }

        // Debug
        std::cout << "After rotor " << k << ": " << var1 << "\n";
    }

    // 5 Resultado final
    std::cout << "\nMensaje descifrado:\n";
    std::cout << var1 << "\n";
    system("pause");
}