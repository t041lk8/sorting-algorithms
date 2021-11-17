/***---------------------------------------****
****---------Курс программирование---------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : 2-3.CPP                      *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.                 *
* Modified By  : Zhbanov I.A.                 *
* Created      : 03/11/2021                   *
* Last Revision: 05/11/2021                   *
* --------------------------------------------*
* Comment      : Третья лабораторная работа   *
****------------------------------------------*/

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

const int MAXIMUM = 20, MINIMUM = -20;  //минимум и максимум для генерации случайных чисел
const int FIRSTSTEPSIZE = 10;           //размер вектора для первого этапа
const int SECONDSTEPSIZE = 10000;       //размер вектора для второго этапа

void PrintSequence(const vector<int>& M, const int N);                     //вывод последовательности
void GetRandomSequence(vector<int>& M, const int N);					   //инициализация последовательности случайных чисел
void GetDecreasingSequence(vector<int>& M);								   //инициализация убывающей последовательности 
void SelectionSort(vector<int>& M, const int N, int& swap, int& count);    //сортировка выбором
void QuickSort(vector<int>& M, int begin, int end, int& swap, int& count); //быстрая сортировка

int main()
{
	setlocale(LC_ALL, "Russian");
	/*-------------------------------------------------------------------------------------------------------------------*/
	cout << "============= П Е Р В Ы Й === Э Т А П =============" << endl;
	int swap = 0, count = 0; //счетчик перестановок и счетчик сравнений
	cout << "Последовательность из " << FIRSTSTEPSIZE << " элементов:";
	vector <int> sequence,		//последовательность для сортировки
		         tempSequence;  //вектор для сохранения исходной последовательности
	GetRandomSequence(sequence, FIRSTSTEPSIZE); //инициализиурем последовательность случайных чисел
	PrintSequence(sequence, FIRSTSTEPSIZE);     //выводим последовательность на печать
	tempSequence = sequence;                    //запоминаем последовательность для второй сортировки

	cout << "\nСортировка выбором:\n";
	SelectionSort(sequence, FIRSTSTEPSIZE, swap, count); //сортировка выбором
	cout << "\nРезультат:\n";
	PrintSequence(sequence, FIRSTSTEPSIZE);  //выводим отсортированную последовательность
	cout<< "\nКоличество пересылок = " << swap << "\nКоличество сравнений = " << count << endl;
	sequence = tempSequence; //записываем исходную последовательность обратно

	cout << "\nБыстрая сортировка:\n";
	swap = 0, count = 0;									//обнуляем счетчики
	QuickSort(sequence, 0, FIRSTSTEPSIZE - 1, swap, count); //быстрая сортирвка
	cout << "\nРезультат:\n";
	PrintSequence(sequence, FIRSTSTEPSIZE);					//выводим отсортированную последовательность
	cout << "\nКоличество пересылок = " << swap << "\nКоличество сравнений = " << count << endl;
	sequence.clear(); tempSequence.clear(); //очищаем вектора

	/*----------------------------------------------------------------------------------------------------------------------*/
	cout << "\n\n============= В Т О Р О Й === Э Т А П =============" << endl;
	swap = 0, count = 0; //обнуляем счетчики
	cout << "Последовательность из " << SECONDSTEPSIZE << " элементов:" << endl;
	GetRandomSequence(sequence, SECONDSTEPSIZE);  //инициализиурем последовательность случайных чисел
	tempSequence = sequence;					  //запоминаем последовательность для второй сортировки

	cout << "\nСортировка выбором:\n";
	auto start = chrono::steady_clock::now();             //запускаем отчет времни работы сортировки
	SelectionSort(sequence, SECONDSTEPSIZE, swap, count); //сортировка выбором
	auto finish = chrono::steady_clock::now();			  //останавливаем отчет времени работы сортиовки
	cout << "\nРезультат:\n";
	cout << "Количество пересылок = " << swap << "\nКоличество сравнений = " << count << endl;  //выводим результат
	cout << "Время работы = " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " мс\n"; //выводим время работы
	sequence = tempSequence; //записываем исходную последовательность обратно

	cout << "\nБыстрая сортировка:\n";
	swap = 0, count = 0; //обнуляем счетчики
	start = chrono::steady_clock::now();						//запускаем отчет времни работы сортировки
	QuickSort(sequence, 0, SECONDSTEPSIZE - 1, swap, count);	//быстрая сортировка
	finish = chrono::steady_clock::now();						//останавливаем отчет времени работы сортиовки
	cout << "\nРезультат:\n";
	cout << "Количество пересылок = " << swap << "\nКоличество сравнений = " << count << endl; //выводим результат
	cout << "Время работы = " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " мс\n"; //выводим время работы

	/*----------------------------------------------------------------------------------------------------------------------------*/
	cout << "\nОтсортированная последовательность из " << SECONDSTEPSIZE << " элементов по возрастанию:";
	cout << "\nСортировка выбором:\n";
	swap = 0, count = 0;									//обнуляем счетчики
	start = chrono::steady_clock::now();					//запускаем отчет времни работы сортировки
	SelectionSort(sequence, SECONDSTEPSIZE, swap, count);	//сортировка выбором
	finish = chrono::steady_clock::now();					//останавливаем отчет времени работы сортиовки
	cout << "\nРезультат:\n";
	cout << "Количество пересылок = " << swap << "\nКоличество сравнений = " << count << endl; //выводим результат 
	cout << "Время работы = " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " мс\n"; //выводим время работы

	swap = 0, count = 0;										//обнуляем счетчики
	start = chrono::steady_clock::now();						//запускаем отчет времни работы сортировки
	QuickSort(sequence, 0, SECONDSTEPSIZE - 1, swap, count);	//быстрая сортировка
	finish = chrono::steady_clock::now();						//останавливаем отчет времени работы сортиовки
	cout << "\nРезультат:\n";
	cout << "Количество пересылок = " << swap << "\nКоличество сравнений = " << count << endl; //выводим результат
	cout << "Время работы = " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " мс\n"; //выводим время работы
	sequence.clear(); tempSequence.clear(); //очищаем вектора

	/*----------------------------------------------------------------------------------------------------------------------------*/
	cout << "\nОтсортированная последовательность из " << SECONDSTEPSIZE << " элементов по убыванию:";
	GetDecreasingSequence(sequence); //инициализируем убывающую последовательность
	tempSequence = sequence;		 //запоминаем последовательность для второй сортировки
	swap = 0, count = 0;			 //обнуляем счетчики
	cout << "\nСортировка выбором:\n";
	start = chrono::steady_clock::now();					//запускаем отчет времни работы сортировки
	SelectionSort(sequence, SECONDSTEPSIZE, swap, count);	//сортировка выбором
	finish = chrono::steady_clock::now();					//останавливаем отчет времени работы сортиовки
	cout << "\nРезультат:\n";
	cout << "Количество пересылок = " << swap << "\nКоличество сравнений = " << count << endl; //выводим результат
	cout << "Время работы = " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " мс\n"; //выводим время работы
	sequence = tempSequence; //записываем исходную последовательность обратно

	cout << "\nБыстрая сортировка:\n";
	swap = 0, count = 0;										//обнуляем счетчики
	start = chrono::steady_clock::now();						//запускаем отчет времни работы сортировки
	QuickSort(sequence, 0, SECONDSTEPSIZE - 1, swap, count);	//быстрая сортировка
	finish = chrono::steady_clock::now();						//останавливаем отчет времени работы сортиовки
	cout << "\nРезультат:\n";
	cout << "Количество пересылок = " << swap << "\nКоличество сравнений = " << count << endl; //выводим результат
	cout << "Время работы = " << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << " мс\n"; //выводим время работы
	/*--------------------------------------------------------------------------------------------------------------------------*/
	return 0;
}//main


void PrintSequence(const vector<int>& M, //вектор с последовательностью
	const int N)						 //размер последовательности
{
	for (int i = 0; i < N; i++) cout << M[i] << " "; //выводим последовательность
}//PrintSequence

void GetRandomSequence(vector<int>& M,  //вектор с последовательностью
	const int N)						//размер последовательности
{
	srand(time(NULL));
	int diapason = MAXIMUM - MINIMUM; //диапазон
	for (int i = 0; i < N; i++)
	{
		M.push_back(int(rand() % diapason)); //вычисляем значение
	}//for
	cout << endl;
}//GetRandomSequence

void GetDecreasingSequence(vector<int>& M)  //вектор с последовательностью
{
	for (int i = SECONDSTEPSIZE; i > 0; i--)
	{
		M.push_back(i); //вычисляем значение
	}//for
}//GetDecreasingSequence

void SelectionSort(vector<int>& M,  //вектор с последовательностью
	const int N,					//размер последовательности
	int& swap,						//счетчик перестановок
	int& count)						//счетчик сравнений
{
	swap = 0, count = 0; //обнуляем счетчики
	int temp,			 //переменная для хранения
		key;			 //индекс для поиска
	for (int i = 0; i < N - 1; i++)
	{
		temp = M[i]; //запоминаем значение последовательности
		key = i;     //запоминаем индекс этого значения
		for (int j = i + 1; j < N; j++) //проход по следующим элементам
		{
			if (M[j] < M[key]) key = j; //если нынешний элемент меньше того, что мы запомнили, то запоминаем его индекс
			count ++; //увеличиваем счетчик сравнений
		}//for
		if (key != i) //если мы нашли элемент меньше
		{
			//меняем местами меньший элемент и тот, что мы запоминали
			M[i] = M[key];
			M[key] = temp;
			swap++; //увеличиваем счетчик перестановок
		}//if
		if (M.size() == FIRSTSTEPSIZE) //если это последовательность из первого этапа, то выводим её
		{
			PrintSequence(M, N); //выводим последовательность
			cout << "Количество пересылок = " << swap << ", количество сравнений = " << count << endl; //выводим счетчики
		}//if
	}//for
}//SelectionSort

void QuickSort(vector<int>& M,  //вектор с последовательностью
	int begin,					//индекс начала сортировки
	int end,					//индекс конца сортировки
	int& swap,					//счетчик перестановок
	int& count)					//счетчик сравнений
{
	int mid,  //опорный элемент
		temp; //переменная для хранения
	int left = begin, //левая граница сортировки
		right = end;  //правая граница сортировки
	mid = M[(left + right) / 2]; //вычисление опорного элемента
	count++;
	while (left < right) //выполянем пока левая граница слева от правой
	{
		while (M[left] < mid) //если элемент на левой границе меньше опорного
		{
			left++;	 //сдвигаем левую границу вправо
			count++; //увеличиваем счетчик сравнений
		}//while
		while (M[right] > mid) //если элемент на правой границе больше опорного
		{
			right--; //сдвигаем правую границу влево
			count++; //увеличиваем счетчик сравнений
		}//while
		if (left <= right) //если левая граница до сих пор слева от правой
		{
			//меняем местами элементы на левой и правой границах
			temp = M[left];
			M[left] = M[right];
			M[right] = temp;
			count++; //увеличиваем счетчик сравнений
			swap++;  //увеличиваем счетчик перестановок
			left++;  //сдвигаем левую границу вправо
			right--; //сдвигаем правую границу влево
		}//if
		count += 3; //увеличиваем счетчик сравнений
	}//while
	if (M.size() == FIRSTSTEPSIZE) //если это последовательность первого этапа, то выводим её
	{
		PrintSequence(M, FIRSTSTEPSIZE); //выводим последовательность
		cout << "Количество пересылок = " << swap << ", количество сравнений = " << count << endl;
	}//if
	//если правая граница находится справа от начала сортировки, то отправляем на сортировку левую часть
	if (begin < right) QuickSort(M, begin, right, swap, count);
	//если левая граница находится слева от конца сортировки, то отправляем на сортировку правую часть
	if (left < end) QuickSort(M, left, end, swap, count);
}//QuickSort
/*--------End of 2-3.CPP file----------*/