# ENIGMA MACHINE (C++)

Simulación en consola de una máquina de cifrado inspirada en Enigma, desarrollada en C++ para entorno Windows.

## Funcionalidades del proyecto

Este proyecto permite:

- Encriptar mensajes  
- Desencriptar mensajes  
- Configurar rotores personalizados (A, B y C)  
- Guardar configuraciones y mensajes en archivos  

## Descripción del funcionamiento

El programa simula un sistema de cifrado basado en rotores, inspirado en el funcionamiento conceptual de la máquina Enigma histórica.

### Flujo general

1. El usuario selecciona una opción en el menú principal:
   - Encriptar mensaje  
   - Desencriptar mensaje  
   - Configurar rotores  
   - Salir  

2. Se establece el orden de los rotores (por ejemplo: `ABC`, `CBA`, etc.).

3. Cada rotor:
   - Tiene una configuración interna de 26 letras (una permutación del alfabeto).  
   - Posee un carácter *notch* que simula un punto de rotación.  

4. El mensaje:
   - Se limpia automáticamente (solo letras A–Z en mayúsculas).  
   - Se procesa a través de los rotores.  
   - En desencriptado, los rotores se aplican en orden inverso.  

5. El resultado:
   - Se muestra en consola.  
   - En el caso del cifrado, se guarda en `Message/xifrat.txt`.  

## Estructura del proyecto

```text
/Rotors
    RotorA.txt
    RotorB.txt
    RotorC.txt

/Message
    xifrat.txt
    desxifrat.txt

main.cpp
messageEncrypt.cpp
mesageDecrypt.cpp
rotorConfig.cpp
rotorAConfig.cpp
rotorBConfig.cpp
rotorCConfig.cpp
rotorComprobation.cpp
getMessage.cpp
