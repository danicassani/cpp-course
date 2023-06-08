#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Lorry{
    private:
        int id;
        int weight;
        int capacity;

    public:
        Lorry(int id, int weight, int capacity){
            this->id = id;
            this->weight = weight;
            this->capacity = capacity;
        }

        int get_id(){
            return this->id;
        }

        int get_weight(){
            return this->weight;
        }

        int get_capacity(){
            return this->capacity;
        }

};

bool compare_lorries_by_weight(Lorry l1, Lorry l2){
    return l1.get_weight() < l2.get_weight();
}

bool compare_lorries_by_capacity(Lorry l1, Lorry l2){
    return l1.get_capacity() < l2.get_capacity();
}

string lorry_to_string(Lorry lorry){
    return "Lorry " + to_string(lorry.get_id()) + " with weight " + to_string(lorry.get_weight()) + " and capacity " + to_string(lorry.get_capacity());
}
int main(){
    vector<Lorry> lorries;
    lorries.push_back(Lorry(1, 100, 1000));
    lorries.push_back(Lorry(2, 200, 2000));
    lorries.push_back(Lorry(3, 90, 1500));

    cout << "El tamaño del vector es: " << lorries.size() << endl;


    //Imprimir todos los elementos del vector
    sort(lorries.begin(), lorries.end(), compare_lorries_by_weight);
    cout << "Ordenado por peso:" << endl;
    for(int i = 0; i < lorries.size(); i++){
        cout << lorry_to_string(lorries[i]) << endl;
    }
    sort(lorries.begin(), lorries.end(), compare_lorries_by_capacity);
    cout << "Ordenado por capacidad:" << endl;
    for(int i = 0; i < lorries.size(); i++){
        cout << lorry_to_string(lorries[i]) << endl;
    }
    
    
    return 0;
}