#include <iostream>

using namespace std;
/*
Programa que indica qué numero de los dos introducidos por el usuario es mayor.
*/
int main(){

    int num1, num2;
    cout << "Introduce un numero: ";
    cin >> num1;
    cout << "Introduce otro numero: ";
    cin >> num2;

    if(num1 > num2){
        cout << "El primer número (" << num1 << ") es mayor que el primero (" << num2 << ")." << endl;
    }else if(num1 < num2){
        cout << "El segundo número (" << num2 << ") es mayor que el primero (" << num1 << ")." << endl;
    }else{
        cout << "Ambos numeros son iguales: "  << num2 << "." << endl;
    }
}