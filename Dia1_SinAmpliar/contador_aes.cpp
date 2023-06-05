#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombres[] = {"Juan", "Pedro", "María", "Ana", "Luis", "Anastasia"};

    int aes_totales = 0;


    for (int nombre = 0; nombre < sizeof(nombres) / sizeof(nombres[0]); nombre++) {
        int aes_nombre = 0;

        for (int letra = 0; letra < nombres[nombre].size(); letra++) {
            if (nombres[nombre][letra] == 'a' || nombres[nombre][letra] == 'A') {
                aes_totales++;
                aes_nombre++;
            }
        }  
        cout << "Cantidad de aes en " << nombres[nombre] << ": " << aes_nombre << endl;

    }   

    cout << "Cantidad de aes: " << aes_totales << endl;
    return 0;
}