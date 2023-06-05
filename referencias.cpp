#include <iostream>

using namespace std;

int main() {
    string cadena = "Hola mundo";
    string &cadena2 = cadena;
    cout << cadena2 << endl;
    cadena = "Cambiamos cadena";
    cout << cadena2 << endl;

    cadena2 = "Cambiamos cadena2";
    cout << cadena2 << endl;
    cout << cadena << endl;
    return 0;
}