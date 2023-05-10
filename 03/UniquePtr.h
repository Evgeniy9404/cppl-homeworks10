#pragma once
#include <iostream>

template<class T>
struct DefaultDelete
{
	void operator() (T* ptr) const
	{
		delete ptr;
	}

};




template <class T>
class UniquePtr
{
private:
	T* ptr_ = nullptr;

public:
	//1.Конструктор, принимающий сырой указатель.
	UniquePtr(T* ptr) : ptr_(ptr) { std::cout << "UniquePtr " << ptr_ << '\n'; };

	//3.1.Конструктор копирования запрещён
	UniquePtr(const UniquePtr&) = delete;

	//3.2.Оператор присваивания запрещён
	UniquePtr& operator=(const UniquePtr&) = delete;

	// Конструктор перемещения
	UniquePtr(UniquePtr&& other) noexcept: ptr_(other.ptr)
	{
		std::cout << "UniquePtr&& " << this << '\n';
		other.ptr = nullptr;
	}

	//int adress(UniquePtr& )




	//5.Деструктор.
	~UniquePtr() 
	{
		delete ptr_;
		std::cout << "~UniquePtr " << this << '\n';
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

