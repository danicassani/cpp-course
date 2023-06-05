#include <iostream>
#include <list>

using namespace std;


int main(){
    list <string> lista = {"hola", "me", "llamo", "Daniel"};
    int caracteres_totales = 0;
    for(string palabra : lista){
        int longitud_palabra = palabra.size();
        
        cout << "La palabra \"" << palabra << "\" tiene " << longitud_palabra << " caracteres." <<endl;

        caracteres_totales += longitud_palabra;

    }

    cout << "En total, hay " << caracteres_totales << " caracteres totales." << endl;
}