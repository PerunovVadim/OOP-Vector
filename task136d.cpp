//Автор - Перунов Вадим, гр. ИВТ-22
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <vector>
#include "task136dUnit.h"

const float eps = 10e-3;
const int limit = 100;
const int accuracy = 3;
using namespace std;

int main(){
	srand(time(0));	//задает начальную точку для создания ряда псевдослучайных целых чисел

	vector<double> c {5,6,7,8};
	assert(fabs(array_sqr_summ(c,4) - 174) == 0);
	vector<double> d {5.76,6.88,7.32,8.55};
	assert(fabs(array_sqr_summ(d,4) - 207.1969) <= eps);
	vector<double> e {57.986,44.238,97.132,33.575,1,0};
	assert(fabs(array_sqr_summ(e,6) - 15882.282889) <= eps);

	int n; //размер массива
	vector<double> a;//указатель на массив 
	string fname;//имя файла для загрузки/сохранения

	cout << "If you want to load array from\ntext file - press F\ntype file - press T\nsomething else to generate the new array ";
	char smarker;//символ для подтверждения загрузки/сохранения
	cin >> smarker;
	if (smarker == 'F' or smarker == 'f'){ 
		cout <<"Input file name \n";
		cin >> fname;//ввод имени файла для считывания массива

		try{
			n = size_file(fname);//определение числа элементов файла
		}
		catch (const runtime_error err){
			cout << err.what();
			return 1;
		}

		a.resize(n);//выделение памяти под массив
		array_file_fill(a,fname);//заполнение массива из файла
	}
	else if (smarker == 'T' or smarker == 't'){
			cout <<"Input file name \n";
			cin >> fname;//ввод имени файла для считывания массива

			try{
				n = size_type_file(fname);
			}
			catch (const runtime_error err){
				cout << err.what();
				return 1;
			}

			a.resize(n);
			array_type_read(a,n,fname);
		}
		else {
			cout << "Input length of array\n";
			cin >> n;
			a.resize(n);//выделение памяти под массив
			array_fill_random(a,n,limit,accuracy);//заполнение массива случайными числами
		}
	
	cout << "\nArray: ";
	array_out(a,n);//вывод массива
	cout << "Sum of array equal " << array_sqr_summ(a,n);

	cout << "\n\nIf you want to save array in\ntext file - press F\ntype file - press T\npress something else if you don't want to save array ";
	cin >> smarker;

	if (smarker == 'F' or smarker == 'f'){
		cout <<"Input file name \n";
		cin >> fname;//ввод имени файла для записи массива
		try{
			array_file_out(a,n,fname);//вывод массива в файл
		}
		catch (const runtime_error err){
			cout << err.what();
			return 1;
		}
		cout <<"Array saved in file";
	}
	else if (smarker == 'T' or smarker == 't'){
			cout <<"Input file name \n";
			cin >> fname;//ввод имени файла для записи массива

			try{
				array_type_out(a,n,fname);
			}
			catch (const runtime_error err){
				cout << err.what();
				return 1;
			}

			cout <<"Array saved in file";
		}
	//delete[] a;//удаление массива
}