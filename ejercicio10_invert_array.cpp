#include <iostream>

using namespace std;


int main(){

    int enteros[] = {1, 2, 3, 4, 5, 6};

    int cantidad_enteros = sizeof(enteros) / sizeof(int);

    int enteros_invertidos [cantidad_enteros];
    
    for ( int i = 0; i < cantidad_enteros; i++ ){
        int posicion_destino = cantidad_enteros - i - 1;

        enteros_invertidos[posicion_destino] = enteros[i];

    }

    cout << "Array original: [ ";

    for (int entero : enteros ){
        cout << entero << " ";
    }
    cout << "]" << endl;

    cout << "Array invertido: [ ";
    for (int entero : enteros_invertidos ){
        cout << entero << " ";
    }
    cout << "]" << endl;
    
    

}