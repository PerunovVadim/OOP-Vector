// todo: doc
///заполняет массив arr размером arr_size случайными числами. limit - в пределах какого числа генерировать число, accur - точность числа
void array_fill_random(std::vector<double> arr, unsigned arr_size,int limit,int accur);

///находит сумму квадратов массива arr размером arr_size
double array_sqr_summ(std::vector<double> arr,unsigned arr_size);

///выводит массив arr размером arr_size
void array_out(std::vector<double> arr,unsigned arr_size);

///выводит в файл с названием file_name массив arr размером arr_size
void array_file_out(std::vector<double> arr, unsigned arr_size,std::string &file_name);

///определяет число строк в файле с названием file_name
long int size_file(std::string& file_name);

///заполняет массив массив arr размером arr_size значениями из файла с названием file_name
void array_file_fill(std::vector<double> arr, std::string& file_name);

///выводит массив arr размером arr_size в бинарный файл с названием file_name
void array_type_out(std::vector<double> arr, unsigned arr_size,std::string& file_name);

///считывает массив arr размером arr_size из бинарного файла с названием file_name
void array_type_read(std::vector<double> arr, unsigned arr_size,std::string& file_name);

///определяет количество чисел, которые содержит бинарный файл с названием file_name
long int size_type_file(std::string& file_name);