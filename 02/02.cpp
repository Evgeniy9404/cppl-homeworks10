// Домашнее задание к занятию «Умные указатели»
// # Задача 2. Устранение пересечения

#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    //std::shared_ptr<node> parent; // меняем std::shared_ptr на std::weak_ptr
    std::weak_ptr<node> parent; // меняем std::shared_ptr на std::weak_ptr
    node(int value) : m_value{ value } { std::cout << this << " constructor called\n"; };
    ~node() { std::cout << this << " destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1); // создание указателя node1 на объект 1 класса node
        auto node2 = std::make_shared<node>(2); // создание указателя node2 на объект 2 класса node

        //std::cout << node1 << " node1 " << node1->m_value << "\n";
        //std::cout << node2 << " node2 " << node2->m_value << "\n";

        //std::cout << " before node1.use_count() " << node1.use_count() << "\n";
        //std::cout << " before node2.use_count() " << node2.use_count() << "\n";

        node1->parent = node2;
        node2->parent = node1;

        //std::cout << " after node1.use_count() " << node1.use_count() << "\n";
        //std::cout << " after node2.use_count() " << node2.use_count() << "\n";
    }

    return 0;
}