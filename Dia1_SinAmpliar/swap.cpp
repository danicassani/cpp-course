#include <iostream>
 using namespace std;
//Swap function to swap 2 numbers
void swap(int *num1, int *num2)
{
    int temp;  	 	
    //Copy the value of num1 to some temp variable
    temp = *num1;
    
    cout << "&NUM1: " << &num1 << " Valor: " << *num1 << endl; 
    cout << "&NUM2: " << &num2 << " Valor: " << *num2 << endl << endl; 

    //Copy the value of num2 to num1
    *num1 = *num2;
    //Copy the value of num1 stored in temp to num2
    *num2 = temp;
    cout << "&NUM1: " << &num1 << " Valor: " << *num1 << endl; 
    cout << "&NUM2: " << &num2 << " Valor: " << *num2 << endl << endl; 
}

void swap2(int num1, int num2){
    // Con este método no se modifican los valores en memoria, sino que se crean valores diferentes y se destruyen al final de la función.
    int temp;  	 	
    //Copy the value of num1 to some temp variable
    temp = num1;
    
    cout << "Dirección: " << &num1 << " Valor: " << num1 << endl; 
    cout << "Dirección: " << &num2 << " Valor: " << num2 << endl << endl; 
    
    //Copy the value of num2 to num1
    num1 = num2;

    //Copy the value of num1 stored in temp to num2
    num2 = temp;

    cout << "&Dirección: " << &num1 << " Valor: " << num1 << endl; 
    cout << "&Dirección: " << &num2 << " Valor: " << num2 << endl; 
}

 int main()
 {
    int num1, num2;
    //Inputting 2 numbers from user

    cout << "\nEnter the first number : ";
    cin >> num1;
    cout << "\nEnter the Second number : ";
    cin >> num2;

    //Passing the addresses of num1 and num2
    cout << "Dirección: " << &num1<<endl;
    cout << "Dirección: " << &num2<<endl << endl;
    swap(&num1, &num2);
    // swap2(num1, num2);

    //Printing the swapped values of num1 and num2
    cout << "First number : " << num1 << endl;
    cout << "Second number: " << num2 << endl;
    return (0);
}