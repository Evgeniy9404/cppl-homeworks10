// Домашнее задание к занятию «Умные указатели»
// Задача 3*. std::unique_ptr своими руками

#include <iostream>
#include <vector>
#include <memory>

#include "UniquePtr.h"


int main()
{
    
    auto ptr1 = UniquePtr<int>(new int(111));
    auto ptr2 = UniquePtr<int>(new int(222));
    
    //ptr1 = ptr2;

    std::cout << "*ptr1\t  " << *ptr1 << '\n';
    std::cout << "*ptr2\t  " << *ptr2 << '\n';

    std::cout << "ptr1\t  " << ptr1.release() << '\n';
    std::cout << "ptr2\t  " << ptr2.release() << '\n';

    UniquePtr<int> x;



    std::cout << "\n\nHello World!\n";
};