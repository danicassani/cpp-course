#include <iostream>
#include <list>

using namespace std;

int item_by_index(list <int> list1, int index){

}

int main(){
    list <int> list1;
    // list1 = {1,2,5,6};
    list1.push_front(2);
    list1.push_front(1);
    list1.push_back(5);
    list1.push_back(6);

    

    cout << "El tamaño de la lista es: " << list1.size() << endl;

    list1.sort();
    for (int item : list1){
        cout << item << endl;
    }



    return 0;
}