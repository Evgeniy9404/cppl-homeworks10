# Домашнее задание к занятию «Умные указатели»

Выполнив это задание, вы научитесь использовать умные указатели из STL.

### Цель задания

Научиться работать с умными указателями. 

### Подготовка к выполнению домашнего задания

1. Для выполнения задания и прохождения курса нужен компьютер с операционной системой Windows или macOS и установленной на нём Microsoft Visual Studio 2022, готовой для разработки консольных программ на C++.
2. Аккаунт на [GitHub](https://github.com/). [Инструкция по регистрации на GitHub](https://github.com/netology-code/cppm-homeworks/tree/main/common/sign%20up).
3. Система контроля версий [Git](https://git-scm.com/), установленная локально. [Инструкция по установке Git](https://github.com/netology-code/cppm-homeworks/tree/main/common/download).

### Инструкция по выполнению домашнего задания

[Инструкция дана по ссылке](https://github.com/netology-code/cppm-homeworks/blob/main/common/readme.md).

------

### Задание 1

[Клонирование объекта класса](01).
<details>
# Задача 1. Клонирование объекта класса

### Описание
Бывает полезно быстро создать копию объекта, которая самостоятельно управляет своей памятью.
Если объект класса тяжёлый и имеет много данных на стеке, то целесообразнее возвращать unique_ptr.

В этом задании нужно написать функцию `clone` для класса трёхдиагональной матрицы, которая возвращает `std::unique_ptr`. Код класса трёхдиагональной матрицы ниже:

``` C++
#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    // clone()
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    return 0;
}
```

</details>

### Задание 2

[Устранение пересечения](02).
<details>
# Задача 2. Устранение пересечения

### Описание
Исправьте в коде ошибку, из-за которой не освобождаются ресурсы.
Сообщение `destructor called` должно быть выведено 2 раза.

``` C++
#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::shared_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
    }

    return 0;
}

```

</details>

### Задание 3*

[std::unique_ptr своими руками](03).
<details>
# Задача 3*. std::unique_ptr своими руками

### Описание
Нужно создать упрощённый аналог `std::unique_ptr`.

В шаблонном классе должны быть реализованы функции:
1. Конструктор, принимающий сырой указатель.
2. Перегружен оператор `*` для получения объекта.
3. Запрещены оператор присваивания и конструктор копирования.
4. Метод release, который освобождает владение и возвращает сырой указатель.
5. Деструктор.

</details>

### Правила приёма домашней работы

Чтобы сдать домашнее задание, прикрепите в личном кабинете ссылку на ваш репозиторий.

### Критерии оценки домашней работы

1. В личном кабинете прикреплена ссылка на репозиторий с кодом для заданий 1 и 2 (обязательно) и 3 (по желанию).
2. В ссылке содержится код, который при запуске выполняет описанный в задании алгоритм.