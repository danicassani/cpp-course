#include <iostream>
#include <list>

using namespace std;

/*
Programa que indica que cantidad de numeros pares hay en un array de int
*/

int main(){
    list<int> lista = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 22};
    int pares = 0;

    for(int item : lista){
        if(item % 2 == 0){
            pares++;
        }
    }

    cout << "Hay " << pares << " pares en el list." << endl;
}