#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

// Callback functions for different operations
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}
// Function that performs an operation using a callback
void performOperation(int (*callback)(int, int), int x, int y)
{
    std::cout << "The result of the operation is: " << callback(x, y) << "\n";
}

int main(int argc, char *argv[]){
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <num1> <op> <num2>\n";
        return 1;
    }

    int num1 = std::stoi(argv[1]);
    char op = argv[2][0];
    int num2 = std::stoi(argv[3]);
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