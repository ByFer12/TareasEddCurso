#include <iostream>
#include <stack>

// Función para mover un disco de una torre a otra
void moverDisco(std::stack<int>& origen, std::stack<int>& destino) {
    int disco = origen.top();  // Obtiene el disco superior de la torre de origen
    origen.pop();  // Elimina el disco superior de la torre de origen
    destino.push(disco);  // Coloca el disco en la torre de destinozsdsd
}

// Función para imprimir el estado actual de las torres
void imprimirTorres(const std::stack<int>& torreA, const std::stack<int>& torreB, const std::stack<int>& torreC) {
    std::cout << "Torre A: ";
    std::stack<int> tempA = torreA;  // Crea una copia temporal de la torre A
    while (!tempA.empty()) {  // Itera sobre la copia temporal de la torre A
        std::cout << tempA.top() << " ";  // Imprime el disco superior
        tempA.pop();  // Elimina el disco superior de la copia temporal
    }
    std::cout << std::endl;

    // (Se repiten procesos similares para las torres B y C)
     std::cout << "Torre B: ";
    std::stack<int> tempB = torreB;
    while (!tempB.empty()) {
        std::cout << tempB.top() << " ";
        tempB.pop();
    }
    std::cout << std::endl;

    std::cout << "Torre C: ";
    std::stack<int> tempC = torreC;
    while (!tempC.empty()) {
        std::cout << tempC.top() << " ";
        tempC.pop();
    }
    std::cout << std::endl;
}

// Función principal para jugar a las Torres de Hanoi
void jugarTorresHanoi(int numDiscos) {
    std::stack<int> torreA, torreB, torreC;  // Se crean tres pilas para representar las torres

    // Inicializar la torre A con los discos
    for (int i = numDiscos; i >=1 ; i--) {
        torreA.push(i);  // Se agregan los discos a la torre A en orden descendente
    }

    char origen, destino;  // Variables para almacenar las posiciones de origen y destino

    // Bucle principal del juego
    while (torreC.size() != numDiscos) {  // Mientras la torre C no esté llena
        imprimirTorres(torreA, torreB, torreC);  // Imprime el estado actual de las torres

        // Solicita al usuario las posiciones de origen y destino
        std::cout << "Ingrese la posición de origen (A, B o C): ";
        std::cin >> origen;
        std::cout << "Ingrese la posición de destino (A, B o C): ";
        std::cin >> destino;

        // Obtiene las referencias a las torres de origen y destino según las posiciones ingresadas
        std::stack<int>& torreOrigen = (origen == 'A') ? torreA : (origen == 'B') ? torreB : torreC;
        std::stack<int>& torreDestino = (destino == 'A') ? torreA : (destino == 'B') ? torreB : torreC;

        // Realiza las validaciones necesarias y mueve el disco si el movimiento es válido
        if (torreOrigen.empty()) {
            std::cout << "La torre de origen está vacía. Intente de nuevo." << std::endl;
        } else if (!torreDestino.empty() && torreOrigen.top() > torreDestino.top()) {
            std::cout << "No puede mover un disco sobre uno más pequeño. Intente de nuevo." << std::endl;
        } else {
            moverDisco(torreOrigen, torreDestino);  // Llama a la función para mover el disco
        }
    }

    std::cout << "¡Has ganado!" << std::endl;  // Mensaje de victoria al completar el juego
}

// Función principal
int main() {
    int numDiscos;
    std::cout << "Ingrese el número de discos (máximo 7): ";
    std::cin >> numDiscos;  // Solicita al usuario que ingrese el número de discos

    jugarTorresHanoi(numDiscos);  // Llama a la función para jugar a las Torres de Hanoi

    return 0;  // Retorna 0 para indicar que el programa se ejecutó correctamente
}
