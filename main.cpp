#include <iostream>
using namespace std;

template<typename T>
//Основний метод, приймає 3 аргументі, перший масив, другий та розмір цих масивів
bool checkingAlg(T *str1, T *str2 , int size)
{

	//находимо перший элемент першого масива
	char firstEl = str1[0];
	//k - це ітератор для друго масива
	int k = 0;
	while (firstEl != str2[k])
	{
		//якщо другий масив це зсув першого, то находимо місце, де знаходится перший елемент першого масива
		k++;
		//якщо такого місця немає => масиви різні
		if (k > size) return false;
		
	}
	//після того як знайшли потрібну точку старту, перевіряємо всі ішні елементи рядка на корректність елементів та правильність місцезнаходження
	for (int i = 0; i < size; i++)
	{
		if (k>=size)
			k = 0;

		//якщо хоча би один різний => рядки не є зсувом один одного
		if (str1[i]!=str2[k])
			return false;

		k++;
	}
	//повертаємо true, якщо все в нормі
	return true;
}


int main()
{
	//Варіант №2 
	//Розробіть алгоритм, який за лінійний час визначав би, чи є текстовий рядок Т циклічним зсувом іншого рядка Т* (наприклад, abc та cab).
	setlocale(LC_ALL, "rus");
	const int size = 8;
	char* str1 = new char [size] {"zxcvbnm"};
	char* str2 = new char [size] {"nmzxcvb"};
	cout << checkingAlg(str1, str2, size-1)<<endl;
	system("pause");
	return 0;
}