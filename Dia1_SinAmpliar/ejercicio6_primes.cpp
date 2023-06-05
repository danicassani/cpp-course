#include <iostream>

using namespace std;

/*
Programa que indique si un número es o no primo
*/

int main(){
    int num;
    cout << "Introduce un número entero positivo: ";
    cin >> num;

    if(num < 0){
        cout << "El número introducido no es válido." << endl;
        return 0;
    }

    bool esPrimo = true;


    for(int i = 2; i < num; i++){
        if(num % i == 0){
            esPrimo = false;
            break;
        }
    }

    if(esPrimo){
        cout << "El número " << num << " es primo." << endl;
    }else{
        cout << "El número " << num << " no es primo." << endl;
    }
    return 0;
}