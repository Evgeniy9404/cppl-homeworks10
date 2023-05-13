#pragma once
#include <iostream>
#include <utility>

template <class T>
class UniquePtr
{
private:
	T* ptr_ = nullptr;

public:

	//1.Конструктор по умолчанию
	UniquePtr() { std::cout << "UniquePtr Default Constructor  " << this << '\n'; };

	//1.Конструктор, принимающий сырой указатель.
	UniquePtr(T* ptr) : ptr_(ptr) { std::cout << "UniquePtr(T* ptr) " << this << '\n'; };

	//2.Перегружен оператор* для получения объекта.
	T& operator*() const
	{
		return *ptr_;
	}

	//2.Перегружен оператор->.
	T* operator->() const
	{
		return ptr_;
	}

	//3.1.Конструктор копирования запрещён
	UniquePtr(const UniquePtr&) = delete;

	//3.2.Оператор присваивания запрещён
	UniquePtr& operator=(const UniquePtr&) = delete;

	// Конструктор перемещения
	UniquePtr(UniquePtr&& other) noexcept: ptr_(other.ptr_)
	{
		std::cout << "UniquePtr&& " << this << '\n';
		other.ptr_ = nullptr;
	}

	//4.Метод release, который освобождает владение и возвращает сырой указатель.
	T* release() noexcept
	{
		//подсмотрел в memory.h
		T* _Tmp = ptr_;
		ptr_ = nullptr;
		return _Tmp;

		
	}

	//5.Деструктор.
	~UniquePtr() 
	{
		std::cout << "~UniquePtr " << this << '\n';
		delete ptr_;
	};
};


template<class T>
void print(const T& v0)
{
	for (auto& i : v0)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

};

