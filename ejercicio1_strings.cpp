#include <iostream>

using namespace std;

int main(){
    string nombre;
    cout << "Introduzca su nombre: ";
    // cin >> nombre;
    getline(cin, nombre);
    
    int size = nombre.size();
    cout << "Longitud: "<< size << endl;
    cout << "Corrompiendo nombre..." << endl;
    nombre [0] = 'X';
    nombre [size - 1] = 'x';
    cout << "Nombre corrupto: " << nombre << endl;
    return 0;
}