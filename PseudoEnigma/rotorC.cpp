#include <iostream>
#include <fstream>
#include <string>
#include "rotorComprobation.h" // Función que verifica la configuración del rotor
#include <Windows.h>           // Para Sleep(), GetAsyncKeyState() y system("pause")

// Función que configura el rotor C
// Retorna true (1) si la configuración falla o false (0) si se cancela
bool rotorCConfig()
{
    char notch = 'Z'; // Posición inicial del notch
    system("cls");
    std::cout << "Rotor C configuration:\n";

    // Bucle infinito hasta que el usuario cancele o complete la configuración
    while (true)
    {
        // Si se presiona ESC, salir de la configuración
        if (GetAsyncKeyState(VK_ESCAPE) == -32767)
        {
            return 0; // Cancelar configuración
        }

        system("pause"); // Pausa para que el usuario esté listo
        system("cls");
        std::cout << "Starting configuration of rotor C...\n";
        std::cout << "Insert the characters ordenation:";

        std::string rotorConfi; // Guardará la ordenación ingresada por el usuario
        Sleep(100);             // Pequeña pausa para evitar detección errónea de teclas

        // Verificar la configuración usando rotorComprobation()
        // Retorna true si hay algún error en la configuración
        if (rotorComprobation(rotorConfi, 'C', notch))
        {
            return 1; // Error en la configuración
        }
    }
}
