#include <iostream>

using namespace std;

int main(){

    int variable = 5;
    int *pointer = &variable;

    cout << "variable (value stored in 'variable'): " << variable << endl;
    cout << "&variable (memory address of 'variable'): " << &variable << endl << endl;

    cout << "pointer (memory address which 'pointer' is pointing to): " << pointer << endl;
    cout << "*pointer (value stored in the memory address which 'pointer' is pointing to): " << *pointer << endl;
    cout << "&pointer (memory address where the pointer is stored): " << &pointer << endl;

}