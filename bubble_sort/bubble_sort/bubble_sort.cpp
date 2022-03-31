// bubble_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

int* BubbleSort(int* arr, int n)
{
	int count_comparison = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
				count_comparison++;
			}
		}
	}
	cout << endl << count_comparison << endl;
	return arr;
}

int* InsertionSort(int* arrayPtr, int length) // сортировка вставками
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item, 
		count_comparison = 0; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;

			count_comparison++;
		}
	}
	cout << endl << count_comparison << endl;
	return arrayPtr;
}

void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
}

int* InputArr() //Звездочка это мммасив, а колличество звездочек обозначает размерность массива. Указатели — это с самого начала переменные, уже в которых хранится адрес других переменных.
{
	int n;
	cout << "input arr size: ";
	cin >> n;
	auto arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cout << "input element " << i;
		cin >> arr[i];
	}
	return arr;
}

int* RandomGen(int n)
{
	srand(time(0));//Генерирует зерно для создания случайных чисел
	auto arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	return arr;
}

void MeasureTimeBub(int n)
{
	chrono::time_point<chrono::high_resolution_clock> start, stop;
	auto arr = RandomGen(n);
	start = chrono::high_resolution_clock::now();
	BubbleSort(arr, n);
	stop = std::chrono::high_resolution_clock::now();

	cout << "bub elapsed time for n = " << n << " is: " << chrono::duration_cast<chrono::milliseconds> (stop - start).count() << "\n";
}

void MeasureTimeIns(int n)
{
	chrono::time_point<chrono::high_resolution_clock> start, stop;
	auto arr = RandomGen(n);
	start = chrono::high_resolution_clock::now();
	InsertionSort(arr, n);
	stop = std::chrono::high_resolution_clock::now();

	cout << "ins elapsed time for n = " << n << " is: " << chrono::duration_cast<chrono::milliseconds> (stop - start).count() << "\n";
}


int main()
{
	int n = 7;
	auto arr = new int[] { 0, -2, 3, -6, 0, 5, 10 };
	arr = RandomGen(n);
	PrintArr(arr, n);
	cout << endl;
	arr = BubbleSort(arr, n);
	PrintArr(arr, n);
	cout << endl;

	for (size_t i = 2; i <= 6; i++)
	{
		MeasureTimeBub(pow(10, i));
		MeasureTimeIns(pow(10, i));
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
