#include <iostream>
#include <fstream>
#include <string>

std::string getMessage() {
    std::string messageToCypher;
    std::string cleanMessage;

    std::cout << "Introduce un mensaje para cifrar: ";
    std::getline(std::cin, messageToCypher);

    for (int i = 0; i < messageToCypher.length(); i++) {
        char c = messageToCypher[i];

        // Convertir manualmente a mayúscula
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');  
        }

        // Solo aceptar A-Z
        if (c >= 'A' && c <= 'Z') {
            cleanMessage += c;
        }
    }

    return cleanMessage;
}