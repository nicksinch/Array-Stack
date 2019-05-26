#pragma once

#include <cassert>
#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 16;

template<typename T>
class Stack
{
	private:

	T* arr;
	int count;
    int capacity;

	void IncreaseCapacity();
	void DecreaseCapacity();

	//help functions
	//used in copy constructor, operator= and desctructor
	void DeleteStack();
	void CopyStack(const Stack<T>& other);

	public:

	Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator=(const Stack<T>& other);
    ~Stack();

	void Push(const T& element);
	void Pop();
	T Top() const;

	int GetCount() const;
    int GetCapacity() const;
	bool IsEmpty() const;

	void Print() const;

	void Clear();
};

template<typename T>
void Stack<T>::IncreaseCapacity()
{
	T* ExtendedArr = new (nothrow) T [this->capacity * 2];
	if(ExtendedArr == nullptr)
	{
		cerr<<"Out of memory!"<<endl;
		assert(false);
	}

	for(int i=0;i<this->capacity;i++)
	{
		ExtendedArr[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = ExtendedArr;
	this->capacity*=2;
}

template<typename T>
void Stack<T>::DecreaseCapacity()
{
	T* DecreasedArr = new (nothrow) T [this->capacity / 2];
	if(DecreasedArr == nullptr)
	{
		cerr<<"Out of memory!"<<endl;
		assert(false);
	}

	for(int i=0;i<this->capacity/2;i++)
	{
		DecreasedArr[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = DecreasedArr;
	this->capacity/=2;
}

template<typename T>
void Stack<T>::CopyStack(const Stack<T>& other)
{
	this->count = other.count;
	this->capacity = other.capacity;
	this->arr = new (nothrow) T [other.capacity];
	if(this->arr == nullptr)
	{
		cerr<<"Out of memory!"<<endl;
		assert(false);
	}
	for(int i=0;i<other.count;i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template<typename T>
void Stack<T>::DeleteStack()
{
	delete[] this->arr;
}

template<typename T>
Stack<T>::Stack() : count(0)
{
    this->arr = new (nothrow) T [DEFAULT_CAPACITY];
    if(this->arr == nullptr)
    {
        cerr<<"Out of memory!"<<endl;
		assert(false);
    }
	this->capacity = DEFAULT_CAPACITY;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	this->CopyStack(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if(this != &other)
	{
		this->DeleteStack();
		this->CopyStack(other);
	}
	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	this->DeleteStack();
}

template<typename T>
void Stack<T>::Push(const T& element)
{
	if(this->count == this->capacity)
	{
		this->IncreaseCapacity();
	}
	this->arr[this->count++] = element;
}

template<typename T>
void Stack<T>::Pop()
{
	assert(this->count > 0);
	this->count--;
	if(this->capacity > DEFAULT_CAPACITY && this->count < this->capacity/2)
	{
		this->DecreaseCapacity();
	}
}

template<typename T>
T Stack<T>::Top() const
{
	assert(this->count > 0);
	return this->arr[this->count-1];
}

template<typename T>
int Stack<T>::GetCount() const
{
	return this->count;
}

template<typename T>
int Stack<T>::GetCapacity() const
{
	return this->capacity;
}

template<typename T>
bool Stack<T>::IsEmpty() const
{
	return this->count == 0;
}

template<typename T>
void Stack<T>::Print() const
{
	cout<<"{";
	for(int i=0;i<this->count-1;i++)
	{
		cout<<this->arr[i]<<",";
	}
	if(this->count>0)
	{
		cout<<this->arr[this->count-1];
	}
	cout<<"}"<<endl;
}

template<typename T>
void Stack<T>::Clear()
{
	if(this->capacity != DEFAULT_CAPACITY)
	{
		delete[] this-> arr;
		this-> arr = new (nothrow) T [DEFAULT_CAPACITY];
		if(this->arr == nullptr)
		{
			cerr<<"Out of memory!"<<endl;
			assert(false);
		}
		this->capacity = DEFAULT_CAPACITY;
	}
	this->count = 0;
}