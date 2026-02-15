#include <iostream>
#include "mesageEncrypt.h"   // Header para la función de encriptación
#include "mesageDecrypt.h"   // Header para la función de desencriptación
#include "rotorConfig.h"     // Header para la configuración de rotores
#include "getMessage.h"      // Header para obtener mensajes del usuario
#include <Windows.h>         // Para Sleep() y GetAsyncKeyState()

int main()
{
    char inputUser;   // Variable para capturar input del usuario (aunque no se usa directamente aquí)
    bool bucle = 1;   // Flag para controlar el bucle interno de selección

    // Bucle principal del programa, muestra menú constantemente
    while (true)
    {
        system("cls"); // Limpiar pantalla en cada iteración
        std::cout << "        ==============================\n";
        std::cout << "            ENIGMA MACHINE\n";
        std::cout << "        ==============================\n";
        std::cout << "            1. Encrypt Message\n\n";
        std::cout << "            2. Decrypt Message\n\n";
        std::cout << "            3. Configure Rotors\n\n";
        std::cout << "            4. Exit\n";

        // Bucle interno que espera la entrada del usuario usando teclas 1-4
        while (bucle)
        {
            // Si se presiona la tecla "1", llamar a la función de encriptación
            if (GetAsyncKeyState(49) == -32767) // 49 es el código ASCII de '1'
            {
                std::cout << "Insert a message to cypher: ";
                // La función messageEncrypt() se define en messageEncrypt.cpp
                messageEncrypt();
                break; // Salir del bucle interno para volver al menú principal
            }

            // Si se presiona la tecla "2", llamar a la función de desencriptación
            if (GetAsyncKeyState(50) == -32767) // 50 es el código ASCII de '2'
            {
                std::cout << "Insert a message to decypher: ";
                mesageDecrypt();
                break;
            }

            // Si se presiona la tecla "3", ir a la configuración de rotores
            if (GetAsyncKeyState(51) == -32767) // 51 es el código ASCII de '3'
            {
                rotorConfig();
                break;
            }

            // Si se presiona la tecla "4", terminar el programa
            if (GetAsyncKeyState(52) == -32767) // 52 es el código ASCII de '4'
            {
                return 1; // Salida inmediata del programa
            }

            Sleep(100); // Pequeña pausa para evitar que el bucle consuma toda la CPU
        }
    }

    return 0; // Aunque nunca se alcanza por el while(true)
}

	