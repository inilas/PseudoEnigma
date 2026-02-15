#include <iostream>
#include <string>
#include <fstream>
#include "rotorABCConfig.h" // Headers de funciones para configurar los rotores A, B y C
#include <Windows.h>        // Para Sleep() y GetAsyncKeyState()

// Función principal para configurar los rotores
void rotorConfig()
{
    system("cls");
    char inputUser;
    std::cout << "rotor configuration\n";
    std::cout << "What rotor do you want to modify?\n";
    std::cout << "    1.Rotor A\n    2.Rotor B\n    3.Rotor C\n    4.Back\n";

    // Bucle para esperar la tecla presionada por el usuario
    while (true)
    {
        // Configuración del Rotor A
        if (GetAsyncKeyState(49) == -32767) // Tecla '1'
        {
            if (rotorAConfig()) // Llama a la función de configuración del Rotor A
                return;         // Salir si hubo algún error
        }

        // Configuración del Rotor B
        if (GetAsyncKeyState(50) == -32767) // Tecla '2'
        {
            if (rotorBConfig())
                return;
        }

        // Configuración del Rotor C
        if (GetAsyncKeyState(51) == -32767) // Tecla '3'
        {
            if (rotorCConfig())
                return;
        }

        // Volver al menú anterior
        if (GetAsyncKeyState(52) == -32767) // Tecla '4'
        {
            return; // Salir de la función
        }

        Sleep(100); // Evitar consumo excesivo de CPU
    }
}

// -------------------------------------------------------------
// Función auxiliar para leer la configuración de un rotor desde un archivo
// - wiring: la ordenación del rotor (alfabeto interno)
// - notch: posición de notch del rotor
// - i: índice del rotor dentro de rotorOrdenation
// - rotorOrdenation: cadena que indica el orden de los rotores (ej. "ABC")
void getRotorConf(std::string& wiring, char& notch, short i, std::string rotorOrdenation)
{
    std::ifstream rotorFile;
    std::string fileName = "Rotors/Rotor" + std::string(1, rotorOrdenation[i]) + ".txt"; // Archivo del rotor
    rotorFile.open(fileName);

    std::cout << "Getting " << fileName << " data\n";

    if (!rotorFile.is_open())
    {
        std::cout << "Critical error, can't open " << fileName; // Error crítico si no se puede abrir
    }

    // Leer la ordenación del rotor
    std::getline(rotorFile, wiring);

    // Leer la letra del notch
    std::string notchLetter;
    std::getline(rotorFile, notchLetter);
    rotorFile.close();

    notch = notchLetter[0]; // Guardar la letra del notch
}

