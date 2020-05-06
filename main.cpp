#include "Vector.h"
#include "VectorFun.h"
#include "Matrix.h"
#include "MatrixFun.h"
#include <iostream>
#include <clocale>


#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <time.h>

#include <vector>
using namespace std;


int main()
{
	setlocale(LC_CTYPE, "Russian");
	Vector<int> v1,v2;
	v1.Set(3,4,41);
	v2.Set(3, 1, 54);
	Vector<int> v3(v1);
	cout << "Проверим работу функции Set, оператора потокового вывода и оператора копирования:" << "v1=" << v1<<endl<< "v2=" << v2<< endl<< "v3=" << v3 << endl;
	cin >> v3;
	cout << "Проверим работу оператора потокового ввода:" << "v3=" << v3 << endl;
	v3 = v1 + v2;
	cout << "Проверим работу оператора суммы и оператора присваивания:" << "v3=" <<v3<< endl;
	v3 = v1 - v2;
	cout << "Проверим работу оператора разности:" << "v3=" << v3 << endl;
	v3 = v1 * v2;
	cout << "Проверим работу оператора умножения вектора на вектор:" << "v3=" << v3 << endl;
	cout << "Сортировка пузырьком за:" <<BubbleSort(v1) << "секунд"<< endl<< "v1=" <<v1<<endl;
	cout << "Сортировка вставкиами за:" << InsertionSort(v2) << "секунд" << endl << "v2=" << v2 << endl;
	cout << "Сортировка пузырьком за:" << QuickSort(v3,0,v3.GetSize()) << "секунд" << endl << "v3=" << v3 << endl;
	Matrix<int> m1, m2,m4;
	m1.Set(3, 2, 1,84);
	m2.Set(3, 2, 41,150);
	m4.Set(2, 3, 41, 150);
	Matrix<int> m3(m1);
	cout << "Проверим работу функции Set, оператора потокового вывода и оператора копирования:" << "m1=" << m1 << endl << "m2=" << m2 << endl << "m3=" << m3 << endl;
	cin >> m3;
	cout << "Проверим работу оператора потокового ввода:" << "m3=" << m3 << endl;
	m3 = m1 + m2;
	cout << "Проверим работу оператора суммы и оператора присваивания:" << "m3=" << m3 << endl;
	m3 = m1 - m2;
	cout << "Проверим работу оператора разности:" << "m3=" << m3 << endl;
	m3 = m1 * m4;
	cout << "Проверим работу оператора умножения матрицы на матрицу:" << "m3=" << m3 << endl;
	v3 = v1*m1;
	cout << "Проверим работу оператора умножения вектора на матрицу:" << "v3=" << v3 << endl;
	v3 = m4 * v1;
	cout << "Проверим работу оператора умножения матрицы на вектор:" << "v3=" << v3 << endl;
	return 0;
}

