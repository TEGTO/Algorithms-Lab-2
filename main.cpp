#include <iostream>
using namespace std;

template<typename T>
bool checkingAlg(T* str1, T* str2, int size)
{
	size -= 1;
	char firstEl = str1[0];
	int k = 0;
	while (firstEl != str2[k])
	{
		k++;
		if (k > size) return false;
		
	}
	for (int i = 0; i < size; i++)
	{
		if (k>=size)
		{
			k = 0;
		}
		if (str1[i]!=str2[k])
		{
			return false;
		}
		k++;
	}
	return true;
}


int main()
{
	setlocale(LC_ALL, "rus");
	const int size = 8;
	char* str1 = new char [size] {"zxcvbnm"};
	char* str2 = new char [size] {"nmzxcvb"};
	cout << checkingAlg(str1, str2, size)<<endl;
	system("pause");
	return 0;
}