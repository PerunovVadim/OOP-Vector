#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <io.h>
#include <stdexcept>
#include <vector>

using namespace std;

// int -> unsigned
///заполняет массив arr размером arr_size случайными числами. limit - в каких пределах генерировать число, accur - точность числа
//
void array_fill_random(vector<double> arr, unsigned arr_size,int limit,int accur){		
	for (unsigned i = 0;i < arr_size;i++)
		arr[i] = rand()%limit + (rand()%accur)/float(accur);
	// todo: args
}


///находит сумму квадратов массива arr размером arr_size
double array_sqr_summ(vector<double> arr,unsigned arr_size){
	double s = 0;//сумматор

	for (unsigned i = 0; i < arr_size; i++){
		s += arr[i]*arr[i];
	}

	return s;
}

///выводит массив arr размером arr_size
void array_out(vector<double> arr,unsigned arr_size){		
	for (unsigned i = 0;i < arr_size;i++)
		cout << arr[i] <<' ';
	cout << endl;
}


///выводит в файл с названием file_name массив arr размером arr_size
/// ???
void array_file_out(vector<double> arr, unsigned arr_size,string &file_name){
	ofstream out;//файл для записи
	out.open(file_name);//открытие файла
	for (unsigned i = 0; i < arr_size;i++)
		out << arr[i] << endl;
	out.close();
}


///определяет число строк в файле с названием file_name
long int size_file(string& file_name){
	int count = 0;//счетчик
	double k;
	ifstream f;//файл для чтения
	f.open(file_name);//открытие файла
	if (f.is_open()){
		while (!(f.eof())){
			count++;
			f >> k;//переход на след. строку
		}

		f.close();
	}
	else throw runtime_error("Error of file opening");

	return count-1;
}

///заполняет массив массив arr размером arr_size значениями из файла с названием file_name
void array_file_fill(vector<double> arr, string& file_name){
	string tmp;
	ifstream f;//файл для чтения
	f.open(file_name);//открытие файла

	if (f.is_open()){
		for (unsigned i = 0;!(f.eof());i++){
			f >> arr[i];
		}
	}
	else throw runtime_error("Error of file opening");
}

///выводит массив arr размером arr_size в бинарный файл с названием file_name
void array_type_out(vector<double> arr, unsigned arr_size,string& file_name){
	ofstream fileType;
	fileType.open(file_name,ios::binary);
	if (fileType.is_open()){
		fileType.write((char*)(&arr),arr_size * sizeof(double));
		fileType.close();
	}
	else throw runtime_error("Error of file opening");
}

///определяет количество чисел, которые содержит бинарный файл с названием file_name
long int size_type_file(string& file_name){
	long int filesize;
	ifstream f;//файл для чтения
	f.open(file_name,ios::binary);//открытие файла
	if (f.is_open()){
		f.seekg(0,ios::end);//перемещение указателя в конец файла
		filesize = f.tellg();//определение позиции указателя
		f.close();
	}
	else throw runtime_error("Error of file opening");
	return filesize/sizeof(double);
}

///считывает массив arr размером arr_size из бинарного файла с названием file_name
void array_type_read(vector<double> arr, unsigned arr_size,string& file_name){
	ifstream fileType;
	fileType.open(file_name,ios::binary);
	if (fileType.is_open()){
		fileType.read((char*)(&arr),arr_size * sizeof(double));
	}
	else throw runtime_error("Error of file opening");
	fileType.close();
}