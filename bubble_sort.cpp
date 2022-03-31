#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

int* BubbleSort(int* arr, int n, bool descending=true)
{
	int count_comparison = 0;

	
	for (int i = 0, counter = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (descending)
			{
				if (arr[i] > arr[j])
				{
					swap(arr[i], arr[j]);//swap меняет местами два элемента массива
					counter++;
					if (counter >= n)
					{
						count_comparison++;
						counter = 0;
					}
				}
			}
			else
			{
				if (arr[i] < arr[j])
				{
					swap(arr[i], arr[j]);
					counter++;
					if (counter >= n)
					{
						count_comparison++;
						counter = 0;
					}
				}
			}
			
		}
	}
	cout << endl << "count comparison " << count_comparison << " * " << n << endl;//количество перестановок
	return arr;
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

int* RandomGen(int n, int seed=0)
{
	srand(seed); //Генерирует зерно для создания случайных чисел
	auto arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	return arr;
}

void MeasureTimeBub(int n) //destending = None добавление случайного массива (всегда по возрастанию)
{
	chrono::time_point<chrono::high_resolution_clock> start, stop;
	auto arr = RandomGen(n);//seed равен 0 по умолчанию для каждого запуска массив будет одинаковый
	start = chrono::high_resolution_clock::now();
	BubbleSort(arr, n);//seed равен 0 по умолчанию для каждого запуска массив будет одинаковый
	stop = std::chrono::high_resolution_clock::now();

	cout << "descending=None\n" 
		<< "bub elapsed time for n = " << n << " is: \n" 
		<< chrono::duration_cast<chrono::nanoseconds> (stop - start).count() << " ns\n"
		<< chrono::duration_cast<chrono::milliseconds> (stop - start).count() << " ms\n"
		<< chrono::duration_cast<chrono::seconds> (stop - start).count() << " s\n"
		<< chrono::duration_cast<chrono::minutes> (stop - start).count() << " min\n"
		<< chrono::duration_cast<chrono::hours> (stop - start).count() << " h\n";
}

void MeasureTimeBub(int n, bool descending)//Добавление случайного масссива и двойная его сортировка (0 или 1)
{
	chrono::time_point<chrono::high_resolution_clock> start, stop;
	auto arr = RandomGen(n);
	arr = BubbleSort(arr, n, descending);
	start = chrono::high_resolution_clock::now();
	BubbleSort(arr, n);
	stop = std::chrono::high_resolution_clock::now();

	cout << "descending="<<descending<< endl
		<< "bub elapsed time for n = " << n << " is: \n"
		<< chrono::duration_cast<chrono::nanoseconds> (stop - start).count() << " ns\n"
		<< chrono::duration_cast<chrono::milliseconds> (stop - start).count() << " ms\n"
		<< chrono::duration_cast<chrono::seconds> (stop - start).count() << " s\n"
		<< chrono::duration_cast<chrono::minutes> (stop - start).count() << " min\n"
		<< chrono::duration_cast<chrono::hours> (stop - start).count() << " h\n";
}


int main()
{
	int n = 7;
	auto arr = new int[] { 0, -2, 3, -6, 0, 5, 10 };
	arr = RandomGen(n, time(0));//создается уникальное зерно от текущего времени (генерируются разные массивы)
	PrintArr(arr, n);
	cout << endl;
	arr = BubbleSort(arr, n);
	PrintArr(arr, n);
	cout << endl;

	for (size_t i = 2; i <= 6; i++)
	{
		cout << "\nelement count : " << pow(10, i) << "----------------------------" << endl;
		MeasureTimeBub(pow(10, i));
		MeasureTimeBub(pow(10, i), false);
		MeasureTimeBub(pow(10, i), true);
	}
}