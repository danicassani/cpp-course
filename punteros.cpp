#include <iostream>

using namespace std;

int main() {

    string food = "Pizza";
    string* ptr = &food;

    // Output the value of food (Pizza)
    cout << food << "\n";

    // Output the memory address of food (0x6dfed4)
    cout << &food << "\n";

    // Output the memory address of food with the pointer (0x6dfed4)
    cout << ptr << "\n";
    

}