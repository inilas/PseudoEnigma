#include <iostream>
#include <fstream>
#include <string>

std::string getMessage() {
    std::string messageToCypher;
    std::string cleanMessage;

    std::getline(std::cin, messageToCypher);

    std::ofstream messageFile;
    messageFile.open("Message.txt");
    
    if (messageFile.is_open()) {
        messageFile << messageToCypher;
    }
    else
    {
        std::cout << "The original message hasn't been able to get saved.";
    }
    messageFile.close();
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