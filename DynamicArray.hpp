
#pragma once

template<class T>
class DynamicArr
{
private:
	T* data;
	size_t capacity;

public:
	DynamicArr();
	~DynamicArr();
	DynamicArr(const DynamicArr<T>&);
	DynamicArr& operator=(const DynamicArr<T>&);

	T& operator[](size_t);
	const T& operator[](size_t) const;

	void addEl(const T&);
	void removeEl(size_t);

	size_t getsize() const;


private:
	void clean();
	void copyFrom(const DynamicArr<T>&);
	void resize(bool);
};

template<class T>
DynamicArr<T>::DynamicArr() : capacity(1)
{
	data = new T[1];
}

template<class T>
DynamicArr<T>::~DynamicArr()
{
	clean();
}

template<class T>
DynamicArr<T>::DynamicArr(const DynamicArr<T>& other)
{
	copyFrom(other);
}

template<class T>
DynamicArr<T>& DynamicArr<T>::operator=(const DynamicArr<T>& other)
{
	if (this != &other)
	{
		clean();
		copyFrom(other);
	}
	return *this;
}

template<class T>
void DynamicArr<T>::clean()
{
	delete[] data;
}

template<class T>
void DynamicArr<T>::copyFrom(const DynamicArr<T>& other)
{
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		data[i] = other.data[i];
	}
}

template<class T>
void DynamicArr<T>::addEl(const T& t)
{
	capacity += 1;
	T* temp = new T[capacity];

	for (size_t i = 0; i < capacity - 2; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;
	data[capacity - 2] = t; //vsichi koito go polzvat trqbwa da imat operator =
}

template<class T>
void DynamicArr<T>::removeEl(size_t idx)
{
	if (capacity == 1)
		return;

	capacity -= 1;
	T* temp = new T[capacity];

	for (size_t i = 0; i < capacity - 1; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;

}

template<class T>
size_t DynamicArr<T>::getsize() const
{
	return capacity - 1;
}


template<class T>
void DynamicArr<T>::resize(bool flag)
{
	if (flag)
	{
		capacity += 1;
	}
	else if (capacity > 2)
	{
		capacity -= 1;
	}
	else return;

	T* temp = new T[capacity];
	for (size_t i = 0; i < capacity - 2; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	temp = nullptr;
}

template <class T>
T& DynamicArr<T>::operator[](size_t idx)
{
	return data[idx];
}

template <class T>
const T& DynamicArr<T>::operator[](size_t idx) const
{
	return data[idx];
}