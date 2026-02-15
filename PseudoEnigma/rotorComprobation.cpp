#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "getMessage.h"  // Para funciones de limpieza y conversión de caracteres

// Función que verifica la configuración de un rotor
// - rotorConfi: la ordenación ingresada por el usuario
// - letter: identifica el rotor ('A', 'B' o 'C')
// - notch: posición de referencia para el rotor
// Retorna true (1) si la configuración fue exitosa
bool rotorComprobation(std::string rotorConfi, char letter, char notch)
{
    std::cin.clear();
    getline(std::cin, rotorConfi);              // Leer la ordenación completa del rotor
    std::string cleanedMessage = cleanMessage(rotorConfi); // Limpiar mensaje: solo A-Z mayúsculas

    // -------------------------------------------------------------
    // Validar que el rotor tenga exactamente 26 caracteres
    if (cleanedMessage.length() != 26)
    {
        std::cout << "Error: Key must contain 26 characters.\n";
        return 0;
    }

    int l = cleanedMessage.length();

    // -------------------------------------------------------------
    // Comprobar que no haya letras repetidas
    for (int i = 0; i < l; i++) {
        if (cleanedMessage[i] == ' ' || cleanedMessage[i] == '0') continue;

        int count = 1;
        for (int j = i + 1; j < l; j++) {
            if (cleanedMessage[i] == cleanedMessage[j]) {
                count++;
                if (count > 1) {
                    std::cout << "ERROR: '" << cleanedMessage[i] << "' repeated " << count << " times\n";
                    return 0;  // Hay duplicado
                }
            }
        }
    }

    // -------------------------------------------------------------
    // Pedir al usuario el notch (posición de referencia) o usar valor por defecto
    while (true)
    {
        std::cout << "Introduce the character notch or press ENTER to default mode: ";
        notch = std::cin.get();

        // Validar que sea una letra o ENTER
        if ((notch >= 'a' && notch <= 'z') || (notch >= 'A' && notch <= 'Z') || notch == '\n')
        {
            if (notch == '\n')
            {
                notch = 'Z'; // Valor por defecto
            }
            break;
        }

        std::cout << "You must put a letter";
        system("cls");
    }

    // Convertir notch a mayúscula
    cleanNotch(notch);
    system("cls");

    // -------------------------------------------------------------
    // Guardar la configuración en un archivo correspondiente al rotor
    std::ofstream rotorABCConfi;
    rotorABCConfi.open("Rotors/Rotor" + std::string(1, letter) + ".txt");

    if (!rotorABCConfi.is_open())
    {
        std::cout << "Error: can't open /Rotors/Rotor" + std::string(1, letter) + ".txt\n";
        return 0;
    }
    else
    {
        rotorABCConfi << cleanedMessage << "\n" << notch; // Guardar rotor y notch
        std::cout << "Configuration completed!";
        rotorABCConfi.close();
        Sleep(700); // Pequeña pausa para que el usuario vea el mensaje
        return 1;
    }
}
