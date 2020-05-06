#include "Vector.h"
#include "Vector.h"
#pragma once


template<class T>
Vector<T>::Vector()
{
	n = 0;
	arr = NULL;
}

// Констуктор инициализатор
template<class T>
Vector<T>::Vector(int size, T*other) 
{
	arr = new T[size];
	
	for (int i = 0; i < size; i++)
		arr[i] = other[i];

}
// Констуктор копирования
template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->n = other.n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = other.arr[i];
}
// Деструктор
template<class T>
Vector<T>::~Vector()
{
	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
		n = 0;
	}
}

// операция индексации константная
template<class T> const T& Vector<T>::operator[](int index) const
{
	if (index < 0 || index >= n)
		abort(); // принудительное завершение программы
	return arr[index];
}

template<class T>
T Vector<T>::GetArr(int i)
{
	if ((i >= 0) || (i < n))
		return arr[i];
	else return arr[0];
}

template<class T>
int Vector<T>::GetSize()
{
	return n;
}

template<class T>
inline void Vector<T>::Set(int size,int min, int max)
{
	delete[] arr;
	n = size;
float d;
	arr = new T[n];
	for (int i = 0; i < n; i++)
	{

		d = float(RAND_MAX - rand()) / RAND_MAX;
		arr[i] = min + T(d * (max - min));

	}
}

// операция присваивания	
template<class T> Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		if (n != other.n)
		{
			delete[] arr;
			n = other.n;
			arr = new T[n];
		}
		for (int i = 0; i < n; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}
template<class T>
bool Vector<T>::operator==(const Vector<T>& other) const
{
	if (strcmp(arr, other.arr) < 0) return true;
	else return false;
}

template<class T>ostream& operator<<(ostream& vyvod, const Vector<T>& other)
{
	vyvod << "(";
	for (int i = 0; i < other.n; i++)
	{
		vyvod << other.arr[i];
		if (i < other.n)
			vyvod << " ";
	}
	vyvod << ")";
	return vyvod;
}
// ввод из потока
template<class T>istream& operator>>(istream& vvod, Vector<T>& other)
{
	int size;
	cout << "Введите размерность:";
	vvod >> size;
	if (other.n != size)
	{
		if (other.arr != NULL)
			delete[] other.arr;
		other.n = size;
		other.arr = new T[size];
	}
	for (int i = 0; i < other.n; i++)
	{
		cout << endl << "Введите значение: ";
	vvod >> other.arr[i];
    }
	return vvod;
}

// операция умножения скаляра на вектор
template<class T> Vector<T> operator*(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v2.n != v1.n)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	T res = 0;
	for (int i = 0; i < v1.n; i++)
		res += v1.arr[i] * v2.arr[i];
	return res;
}

template<class T> Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v2.n != v1.n)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	Vector<T> res(v1.n, 0);
	for (int i = 0; i < v1.n; i++)
		res.arr[i] = v1.arr[i] + v2.arr[i];
	return res;
}

template<class T> Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v2.n != v1.n)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	Vector<T> res(v1.n, 0);
	for (int i = 0; i < v1.n; i++)
		res.arr[i] = v1.arr[i] - v2.arr[i];
	return res;
}
template<class T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	if (v.n != m.str)
	{
		cout << "Размерность вектора должна совпадать с числом строк в матрице" << endl;
		break;
	}
	T* res = new T[m.stlb];
	for (int i = 0; i < m.stlb; i++)
		for (int j = 0; j < v.n; j++)
			res[i] += v.arr[j] * m.arr[j][i];
	return res;
}
template<class T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
	if (v.n != m.stlb)
	{
		cout << "Размерность вектора должна совпадать с числом столбцов в матрице" << endl;
		break;
	}
	T* res = new T[m.str];
	for (int i = 0; i < m.str; i++)
		for (int j = 0; j < v.n; j++)
			res[i] += v.arr[j] * m.arr[i][j];
	return res;
}
template<class T>
clock_t BubbleSort(Vector<T>& other)
{
	clock_t start, finish;
	start = clock();
	T tmp = 0;
	int i, j = 0;
	start = clock();
	for (int i = 0; i < other.n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (other.GetArr(j) > other.GetArr(j + 1))
			{
				tmp = other.GetArr(j);
				other.GetArr(j) = other.GetArr(j + 1);
				other.GetArr(j + 1) = tmp;
			}
		}
	}
	finish = clock();
	return (finish - start);
}
template<class T>
clock_t InsertionSort(Vector<T>& other)
{
	clock_t start, finish;
	start = clock();
	T tmp;
	int location;

	for (int i = 1; i < other.n; i++)
	{
		tmp = other.GetArr(i);
		location = i - 1;
		while (location >= 0 && other.GetArr(location) > tmp)
		{
			other.GetArr(location + 1) = other.GetArr(location);
			location = location - 1;
		}
		other.GetArr(location + 1) = tmp;
	}
	finish = clock();
	return (finish - start);
}
template<class T>
clock_t QuickSort(Vector<T>& other, int first, int last)
{
	clock_t t1, t2, t3;
	t1 = clock();
	int i = first, j = last;
	T tmp;
	T x = other.GetArr((first + last) / 2);

	do {
		while (other.GetArr(i) < x)
			i++;
		while (other.GetArr(j) > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = other.GetArr(i);
				other.GetArr(i) = other.GetArr(j);
				other.GetArr(j) = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		t3 = QuickSort(other, i, last);
	if (first < j)
		t3 = QuickSort(other, first, j);
	t2 = clock();
	return t2 - t1;
}
