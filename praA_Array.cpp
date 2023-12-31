#include <iostream>
#include "ListArray.h"

int main(){
    std::cout << std::boolalpha; // configuramos cout para mostrar true/false en lugar de 0/1.

    ListArray<int> list;

    list.insert(0, 0);
    list.insert(1, 10);
    list.insert(0, -5);
    list.insert(2, 5);
    std::cout << " * Lista: " << std::endl;
    std::cout << list << std::endl; 
    std::cout << " * Lista Invertida: " << std::endl;
    list.invert_list();
    std::cout << list << std::endl;
}
