#include <iostream>

using namespace std;

/*
Programa que muestra los números pares hasta 30
*/

int main(){
    cout << "Solución 1" << endl;	

    for(int i = 1; i <= 30; i++){
        if(i % 2 == 0){
            cout << i << endl;
        }
    }

    cout << "Solución 2" << endl;
    
    for(int i = 1; i <= 15; i++){
        cout << i * 2 << endl;
    }

}