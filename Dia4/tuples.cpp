#include <iostream>
#include <tuple>

using namespace std;

int main(){
    tuple<int, char, bool> tupla(10, 'a', true);

    cout << "Primer valor de la tupla: " << get<0>(tupla) << endl;
    cout << "Segundo valor de la tupla: " << get<1>(tupla) << endl;
    cout << "Tercer valor de la tupla: " << get<2>(tupla) << endl;
    
    return 0;
}