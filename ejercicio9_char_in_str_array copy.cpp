#include <iostream>

using namespace std;


int main(){
    string string_array [] = {"hola", "me", "llamo", "Daniel"};
    int caracteres_totales = 0;
    for(string palabra: string_array){
        int longitud_palabra = palabra.size();
        
        cout << "La palabra \"" << palabra << "\" tiene " << longitud_palabra << " caracteres." <<endl;

        caracteres_totales += longitud_palabra;

    }

    cout << "En total, hay " << caracteres_totales << " caracteres totales." << endl;
}