#include <iostream>

using namespace std;

/*
Programa que indica que cantidad de numeros pares hay en un array de int
*/

int main(){
    int array[10] = {2, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    int pares = 0;

    for(int i = 0; i < 10; i++){
        if(array[i] % 2 == 0){
            pares++;
        }
    }

    cout << "Hay " << pares << " pares en el array" << endl;
}