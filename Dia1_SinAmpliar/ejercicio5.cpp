#include <iostream>

using namespace std;

/*
Programa que muestre los múltiplos de siete (hasta 123).
*/

int main(){
    for (int i = 1; i <= 123; i++){
        if (i % 7 == 0){
            cout << i << endl;
        }
    }
}