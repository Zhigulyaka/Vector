#pragma once
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;
template<class T>
class Matrix {
public:
	Matrix();        
	Matrix(int str_, int stlb_, T** other); 
	Matrix(const Matrix& other);      
	~Matrix();                      
	
	const T& operator()(int str_, int stlb_) const;
	T GetArr(int i,int j);
	void Set(int _str, int _stlb, int min, int max);
	
	int GetStr();
	int GetStlb();
	Matrix& operator=(const Matrix& other); 
	friend ostream& operator<<(ostream& vyvod, const Matrix<T>& other);
	friend istream& operator>>(istream& vvod, Matrix<T>& other);
	bool operator == (const Matrix<T>& other) const;
	friend Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2); 
	friend Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2); 
	friend Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2); 
	T** InitArray(T** other, int str, int stlb, T minVal, T maxVal);
private:
	T** arr;
	int str;    
	int stlb;    
};