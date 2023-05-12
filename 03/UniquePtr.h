#pragma once
#include <iostream>

template <class T>
class UniquePtr
{
private:
	T* ptr_ = nullptr;
	
public:
	//1.�����������, ����������� ����� ���������.
	UniquePtr(T* ptr) : ptr_(ptr) { std::cout << "UniquePtr " << this << '\n'; };

	//2.���������� ��������* ��� ��������� �������.
	T& operator*() const
	{
		return *ptr_;
	}

	//2.���������� ��������->.
	T* operator->() const
	{
		return ptr_;
	}

	//3.1.����������� ����������� ��������
	UniquePtr(const UniquePtr&) = delete;

	//3.2.�������� ������������ ��������
	UniquePtr& operator=(const UniquePtr&) = delete;

	// ����������� �����������
	UniquePtr(UniquePtr&& other) noexcept: ptr_(other.ptr_)
	{
		std::cout << "UniquePtr&& " << this << '\n';
		other.ptr_ = nullptr;
	}

	//4.����� release, ������� ����������� �������� � ���������� ����� ���������.
	T* release()
	{
		ptr_ = nullptr;
		return ptr_;
	}

	//5.����������.
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

