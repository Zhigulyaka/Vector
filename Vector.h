#pragma once
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Matrix.h"
using namespace std;

template<class T>
class Vector:public Matrix<T>
{
public:
	Vector();        
	Vector(int size, T* other); 
	Vector(const Vector& other);      
	~Vector();                      
	const T& operator[](int index) const; 
	T GetArr(int i);
	int GetSize();
	void Set(int size,int min,int max);
	Vector& operator=(const Vector& other); 
	template<class T>
	friend ostream& operator<<(ostream& vyvod, const Vector<T>& other);
	template<class T>
	friend istream& operator>>(istream& vvod, Vector<T>& other);
	bool operator == (const Vector<T>& other) const;
	friend Vector<T> operator*(const Vector<T>& v1, const Vector<T>& v2); 
	friend Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2); 
	friend Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2); 
	friend Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m);
	friend Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v); 
	friend clock_t BubbleSort(Vector<T>& other);
	friend clock_t InsertionSort(Vector<T>& other);
	friend clock_t QuickSort(Vector<T>& other, int first, int last);
private:
	T* arr; 
	int n;   

};
