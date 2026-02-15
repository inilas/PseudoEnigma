#include <iostream>
#include <string>
#include <fstream>
#include "getMessage.h"     // Para funciones relacionadas con obtener mensajes
#include "rotorConfig.h"    // Para funciones de configuración de rotores
#include <Windows.h>        // Para Sleep() y system("pause")

// Función que desencripta un mensaje usando la simulación de rotores estilo Enigma
void mesageDecrypt()
{
    std::string rotorOrdenation;        // Guardará el orden de los rotores seleccionado por el usuario
    bool rotorOrdenationIsCorrect = true; // Flag para validar el orden de los rotores

    system("cls");
    std::cout << "Decrypt section\n";
    system("pause"); // Pausa inicial antes de ingresar al proceso de configuración

    // Pedir al usuario el orden de los rotores hasta que sea correcto
    while (rotorOrdenationIsCorrect)
    {
        system("cls");
        std::cout << "Set rotor ordenation:\n";
        std::getline(std::cin, rotorOrdenation);   // Leer la entrada completa del usuario
        rotorOrdenation = cleanMessage(rotorOrdenation); // Limpiar entrada: mayúsculas y solo A-Z
        rotorOrdenationIsCorrect = correctRotorOrdenation(rotorOrdenation); // Validar orden
    }

    // Animación que simula la preparación de los rotores
    mesageAnimation(rotorOrdenation);

    system("cls");
    std::cout << "Decrypt section:\n";
    std::cout << "Ready to Decrypt!\n";
    std::cout << "What mesage do you want to Decrypt?\n";

    std::string var1;      // Guardará el mensaje a desencriptar
    std::cin.clear();      // Limpiar cualquier error previo en el input
    getline(std::cin, var1);
    var1 = cleanMessage(var1); // Limpiar mensaje: solo letras mayúsculas

    std::cout << var1;     // Mostrar mensaje limpio (opcional)
    system("cls");
    std::cout << "Decrypt section\n";
    system("pause");

    // -------------------------------------------------------------
    // 1. Pedir orden de rotores -> ya realizado antes
    // 2. Cargar la configuración de los rotores
    char notch[3] = {};         // Posición inicial de los rotores
    std::string wiring[3];      // Cables/alfabetos de cada rotor

    // Configurar cada rotor según el orden elegido por el usuario
    for (short i = 0; i < rotorOrdenation.length(); i++)
    {
        getRotorConf(wiring[i], notch[i], i, rotorOrdenation); // Obtener configuración de cada rotor
    }

    short id_leters[100] = {}; // Array auxiliar (aunque no se usa en este fragmento)

    // -------------------------------------------------------------
    // 3. Descifrado (aplicar rotores en orden inverso)

        // Paso A: convertir cada letra usando el rotor k
        for (int i = 0; i < var1.length(); i++)
        {
            int index = -1;

            // Buscar la posición de la letra actual en el alfabeto del rotor
            for (int j = 0; j < wiring[2].length(); j++)
            {
                if (wiring[2][j] == var1[i])
                {
                    index = j;
                    break;
                }
            }

            // Si se encontró la letra, convertirla a su equivalente en A-Z
            if (index != -1)
            {
                var1[i] = 'A' + index;
            }
        }
        // Mostrar el estado del mensaje después de pasar por cada rotor
        std::cout << "After decrypt algoritm: " << var1 << "\n";
    

    // -------------------------------------------------------------
    // 4. Resultado final del mensaje descifrado, y guardar mensaje desencriptado en Message/decrypted.txt
        std::ofstream cypherMessage("Message/decrypted.txt", std::ios::app);

        for (size_t i = 1; i < var1.length() + 1 ; i++)
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
    std::cout << "\nMessage decrypted:\n";
    std::cout << var1 << "\n";

    system("pause"); // Pausa final para que el usuario vea el resultado
}
