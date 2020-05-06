#include "Matrix.h"
#pragma once


template<class T> Matrix<T>::Matrix()

{
	stlb = 0;
	str = 0;
	arr = NULL;
}
template<class T> Matrix<T>::Matrix(int str_, int stlb_, T** other)
{
	arr = new T[str_][stlb_];
	for (int i = 0; i < str_; i++)
		for (int j = 0; j < stlb_; j++)
			arr[i][j] = other[i][j];
}
template<class T> Matrix<T>::Matrix(const Matrix<T>& other)
{
	this->str = other.str;
	this->stlb = other.stlb;
	T** arr = new T * [str];
	for (int i = 0; i < str; i++)
	{
		arr[i] = new int[stlb];
	}
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
			arr[i][j] = other.arr[i][j];
}
template<class T> Matrix<T>::~Matrix()
{
	if (arr != NULL)
	{
		for (int i = 0; i < stlb; i++) 
		{
			delete[]arr[i];
		}
		delete[]arr;
		arr = NULL;
		str = 0;
		stlb = 0;
	}
}


template<class T>
int Matrix<T>::GetStr()
{
	return str;
}

template<class T>
int Matrix<T>::GetStlb()
{
	return stlb;
}
template<class T>
T Matrix<T>::GetArr(int i, int j)
{
	if (i >= 0 || i < str || j >= 0 || j < stlb)
		return arr[i][j];
	else return arr[0][0];
}
template<class T>
inline void Matrix<T>::Set(int _str, int _stlb, int min, int max)
{
	for (int i = 0; i < stlb; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	str = _str;
	stlb = _stlb;
	float d;
	T** arr = new T * [str];
	for (int i = 0; i < str; i++)
	{
		arr[i] = new int[stlb];
	}
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
	{

		d = float(RAND_MAX - rand()) / RAND_MAX;
		arr[i][j] = min + T(d * (max - min));

	}
}
template<class T>
const T& Matrix<T>::operator()(int str_, int stlb_) const
{
	if (str_ < 0 || str_ >= str || stlb_ < 0 || stlb_ >= stlb)
		abort(); // принудительное завершение программы
	return arr[str_][stlb_];
}



// операция присваивания	
template<class T> Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	if (this != &other)
	{
		if (str != other.str || stlb != other.stlb)
		{
			for (int i = 0; i < stlb; i++)
			{
				delete[]arr[i];
			}
			delete[]arr;
			str = other.str;
			stlb = other.stlb;
			T** arr = new T* [str];
			for (int i = 0; i < str; i++) 
			{
				arr[i] = new int [stlb];
			}
		}
		for (int i = 0; i < other.str; i++)
			for (int j = 0; j < other.stlb; j++)
				arr[i][j] = other.arr[i][j];
	}
	return *this;
}
template<class T>
bool Matrix<T>::operator==(const Matrix<T>& other) const
{
	if (str != other.str || stlb != other.stlb)
	{
		return false;
		break;
	}
	for (int i = 0; i < other.str; i++)
		for (int j = 0; j < other.stlb; j++)
			if (arr[i][j] = other.arr[i][j])
			{
				return false;
				break;
			}
	return true;
}
template<class T>
inline T** Matrix<T>::InitArray(T** other, int str, int stlb, T minVal, T maxVal)
{
	float d;
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
		{
			d = float(RAND_MAX - rand()) / RAND_MAX;
			other[i][j] = minVal + T(d * (maxVal - minVal));
		}
	return other;
}
template<class
	T>ostream& operator<<(ostream& vyvod, const Matrix<T>& other)
{
	
	
	for (int i = 0; i < other.str; i++)
	{
        vyvod <<  "(";
		for (int j = 0; j < other.stlb; j++)
			vyvod << other.arr[i][j] << " ";
        vyvod << ")" <<endl;
	}
	vyvod << endl;
	return vyvod;
}
// ввод из потока
template<class
	T>istream& operator>>(istream& vvod, Matrix<T>& other)
{
	int str_;
	int stlb_;
	cout << "Введите количество строк:";
	vvod >> str_;
	cout << endl<<"Введите количество строк:";
	vvod >> stlb_;
	if (other.str != str_ || other.stlb != stlb_)
	{
		if (other.arr != NULL)
			for (int i = 0; i < stlb; i++)
			{
				delete[] other.arr[i];
			}
		delete[] other.arr;
		other.str = str_;
		other.stlb = stlb_;
		other.arr = new T[str_][stlb_];
	}
	for (int i = 0; i < other.str; i++)
		for (int j = 0; j < other.stlb; j++)
		{
			cout << endl << "Введите значение:";
			vvod >> other.arr[i][j];
		}
	return vvod;
}

// операция умножения скаляра на вектор
template<class T> Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2)
{
	if (m1.str != m2.stlb || m1.stlb != m2.str)
	{
		cout << "Число столбцов m1 должно совпадать с числом строк m2, а число строк m1 должно совпадать с числом столбцов m2" << endl;
		break;
	}
	T** res = new T[m1.str][m2.stlb];
	for (int i = 0; i < m1.str; i++)
		for (int j = 0; j < m2.stlb; j++)
			for (int k = 0; k < m1.stlb; k++)
				res[i][j] += m1.arr[i][k] * m2.arr[k][j];
	return res;
}

template<class T> Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2)
{
	if (m1.str != m2.str || m1.stlb != m2.stlb)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	T** res = new T[m1.str][m1.stlb];
	for (int i = 0; i < m1.str; i++)
		for (int j = 0; j < m1.stlb; j++)
			res.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
	return res;
}

template<class T> Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2)
{
	if (m1.str != m2.str || m1.stlb != m2.stlb)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	T** res = new T[m1.str][m1.stlb];
	for (int i = 0; i < m1.str; i++)
		for (int j = 0; j < m1.stlb; j++)
			res.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
	return res;
}

