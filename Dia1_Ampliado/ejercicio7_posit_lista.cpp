#include <iostream>
#include <list>
using namespace std;

/*
Programa que indica que cantidad de positivos que hay en un array de int
*/

int main(){
    int num_positivos = 0;
    list<int> lista = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11};
    
    for (auto const& item : lista){
        if (item > 0){
            num_positivos++;
    }

    cout << "Hay " << num_positivos << " positivos en la lista" << endl;

}