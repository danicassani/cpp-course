#include <iostream>

using namespace std;

/*
Programa que indica que cantidad de positivos que hay en un array de int
*/

int main(){
    int array[10] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    int positivos = 0;

    for(int i = 0; i < 10; i++){
        if(array[i] > 0){
            positivos++;
        }
    }

    cout << "Hay " << positivos << " positivos en el array" << endl;
}