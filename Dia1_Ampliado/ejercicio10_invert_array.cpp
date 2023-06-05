#include <iostream>
#include <list>

using namespace std;


int main(){

    list<int> enteros = {1, 2, 3, 4, 5, 6};

    list<int> enteros_invertidos = enteros;
    enteros_invertidos.reverse();

    cout << "Lista original: [ ";

    for (int entero : enteros ){
        cout << entero << " ";
    }
    cout << "]" << endl;

    cout << "Lista invertida: [ ";
    for (int entero : enteros_invertidos ){
        cout << entero << " ";
    }
    cout << "]" << endl;

}