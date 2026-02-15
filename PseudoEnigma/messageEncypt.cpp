#include <iostream>
#include <string>
#include "getMessage.h"    // Funciones para obtener mensajes
#include <fstream>         // Para guardar mensajes en archivo
#include "rotorConfig.h"   // Funciones de configuración de rotores

// Función que encripta un mensaje usando la simulación de rotores estilo Enigma
void messageEncrypt()
{
    bool rotorOrdenationIsCorrect = 1;   // Flag para validar orden de rotores
    std::string rotorOrdenation;         // Guardará el orden de los rotores elegido por el usuario

    system("cls");
    std::cout << "Encrypt section\n";
    system("pause");                     // Pausa inicial para usuario

    // -------------------------------------------------------------
    // 1. Pedir al usuario el orden de los rotores hasta que sea válido
    while (rotorOrdenationIsCorrect)
    {
        system("cls");
        std::cout << "Set rotor ordenation:\n";
        std::getline(std::cin, rotorOrdenation);         // Leer orden de rotores
        rotorOrdenation = cleanMessage(rotorOrdenation); // Limpiar entrada (solo A-Z, mayúsculas)
        rotorOrdenationIsCorrect = correctRotorOrdenation(rotorOrdenation); // Validar
    }

    // Animación de preparación de los rotores
    mesageAnimation(rotorOrdenation);

    system("cls");
    std::cout << "Ready to encrypt!\n";
    std::cout << "What mesage do you want to encrypt?\n";

    std::string var1;        // Guardará el mensaje a encriptar
    std::cin.clear();
    getline(std::cin, var1); // Leer mensaje completo
    var1 = cleanMessage(var1); // Limpiar mensaje (solo A-Z)

    // -------------------------------------------------------------
    // 2. Preparar los rotores y variables auxiliares
    char notch[3];            // Posición inicial de los rotores
    std::string wiring[3];    // Cables/alfabetos de cada rotor
    short id_leters[100];     // Índices de letras según posición en el rotor

    // Obtener la configuración de cada rotor
    for (short i = 0; i < rotorOrdenation.length(); i++)
    {
        getRotorConf(wiring[i], notch[i], i, rotorOrdenation);
    }

    // -------------------------------------------------------------
    // 3. Inicializar id_leters con la posición de cada letra en el primer rotor
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

    // -------------------------------------------------------------
    // 4. Aplicar encriptación pasando el mensaje por cada rotor
    for (short k = 0; k < rotorOrdenation.length(); k++) // Para cada rotor
    {
        for (short i = 0; i < var1.length(); i++) // Para cada letra del mensaje
        {
            if (var1[i] == notch[k]) // Si la letra coincide con la posición de notch
            {
                var1[i] = wiring[k][id_leters[i]]; // Aplicar rotor
                // Incrementar índices de todas las letras (simula rotación del rotor)
                for (short g = 0; g < var1.length(); g++)
                {
                    id_leters[g] = id_leters[g] + 1;
                }
            }
            else
            {
                var1[i] = wiring[k][id_leters[i]]; // Aplicar rotor normalmente
            }
        }

        std::cout << var1 << "\n"; // Mostrar mensaje tras pasar por el rotor

        // Actualizar id_leters según nueva posición de letras
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

    // -------------------------------------------------------------
    // 5. Guardar mensaje encriptado en archivo "Message/encrypted.txt"
    std::ofstream cypherMessage("Message/encrypted.txt", std::ios::app);

    for (size_t i = 1; i < var1.length() + 1; i++)
    {
        if (i % 5 == 0)            // Insertar espacio cada 5 letras
        {
            cypherMessage << var1[i - 1] << " ";
        }
        else
        {
            cypherMessage << var1[i - 1];
        }
    }
    cypherMessage << "\n";         // Nueva línea al final
    cypherMessage.close();

    std::cout << var1 << "\n";    // Mostrar mensaje encriptado final
    system("pause");              // Pausa final
}
