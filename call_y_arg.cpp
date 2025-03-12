#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

// FUnciones callback para diferentes operaciones
int add(int a, int b){
    return a + b;
}

int multiply(int a, int b){
    return a * b;
}

int subtract(int a, int b){
    return a - b;
}
// Función que realiza la operación usando callback
void performOperation(int (*callback)(int, int), int x, int y){
    std::cout << "The result of the operation is: " << callback(x, y) << "\n";
}
//Función principal
int main(int argc, char *argv[]){
    //Se valida el tamaño de los argumentos para la ejecución
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <num1> <op> <num2>\n";
        return 1;
    }
    //Se obtienen los valores de los argumentos para realizar la operación
    int num1 = std::stoi(argv[1]);
    char op = argv[2][0];
    int num2 = std::stoi(argv[3]);
    //Se realiza la operación según el operador (op) ingresado
    switch (op){
        case '+':
            performOperation(add, num1, num2);
            break;
        case '-':
            performOperation(subtract, num1, num2);
            break;
        case 'x':
            performOperation(multiply, num1, num2);
            break;
        default:
            std::cout << "Invalid operation" << "\n";
    }
    return 0;
}