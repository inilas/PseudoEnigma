#include <iostream>
#include <fstream>
#include <string>

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