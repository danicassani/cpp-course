#include <iostream>
#include <map>
#include <tuple>

#include <algorithm>

using namespace std;

int main(){
    
    map <string, tuple<int, char>> map1;

    map1 = {
        {"elemento1", {1, 'a'}},
        {"elemento2", {2, 'b'}},
        {"elemento3", {3, 'c'}},
        {"elemento4", {1, 'd'}},
        {"elemento0", {2, 'a'}}
    };

    cout << "El tamaño del mapa es: " << map1.size() << endl;

    cout << "El valor de elemento3 es: " << get<0>(map1["elemento3"]) << ", " << get<1>(map1["elemento3"]) << endl;
    
    cout << "Sin ordenar:" << endl;

    for (auto item : map1){
        cout << item.first << " " << get<0>(item.second)<<  " " << get<1>(item.second)<< endl;
    }

    cout << "Ordenado por clave:" << endl;
    sort(map1.begin(), map1.end(), map1.key_comp());

    for (auto item : map1){
        cout << item.first << " " << get<0>(item.second)<<  " " << get<1>(item.second)<< endl;
    }


    return 0;
}