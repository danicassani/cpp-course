#include <iostream>

using namespace std;

int main() {
    while(true){

        
        cout << "Seleccione una opción: " << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Salir" << endl;
        
        int opcion;
        cin >> opcion;
        
        if(opcion == 5) {
            cout << "Hasta pronto!" << endl;
            break;
        }

        int a, b;
        
        cout << "Introduzca el primer número: ";
        cin >> a;
        cout << "Introduzca el segundo número: ";
        cin >> b;
        
        cout << endl;
        
        switch (opcion) {
            case 1:
                cout << "La suma de " << a << " y " << b << " es " << a + b << endl;
                break;
            case 2:
                cout << "La resta de " << a << " y " << b << " es " << a - b << endl;
                break;
            case 3:
                cout << "La multiplicación de " << a << " y " << b << " es " << a * b << endl;
                break;
            case 4:
                cout << "La división de " << a << " y " << b << " es " << float(a) / float(b) << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
        cout << endl;

    }
    return 0;
}