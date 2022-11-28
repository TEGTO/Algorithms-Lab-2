#include <iostream>
using namespace std;
template <typename T>
bool checkingAlg(T * str1, T *str2,int size)
{
    int *indexArr = new int [size];

    int it1 = 0, it2 = 1;
    indexArr[0] = 0;
    while (it2 != size) 
    {
        if (str2[it2] == str2[it1])
        {
            //������ ����� ������� 
            indexArr[it2] = it1 + 1;
            it2++;
            it1++;
        }
        else if (it1 == 0)
        {
            indexArr[it2] = 0;
            it2++;
        }
        else
            it1 = indexArr[it1 - 1];
    }
    it1 = 0, it2 = 0;
    while (it2 != size)
    {
        //���� ������ �������� ����� �� ����, �� �������� ������� ���� �� ������� � ������� ����� �������� 
        if (it1 == size)
            it1 = 0;
        if (str1[it1] == str2[it2])
        {
            //���� �������� ������� �� ��������� ��� � ������� ����� �� ��������� ��������� ������ 
            it1++;
            it2++;
            if (it2 == size)
            {
               
                return true;
            }
        }
        else if (it2 == 0 )
        {
            //���� ������� ��� �� ������ �������� = 0, �� �������� ������, � ����� ���� ������ ���� = ������ ������
            //�� ���� ����������, �� �� ������� ���� ������ ����� �� �� ������� ������ �� � ������� => ������ ���
            it1++;
            if (it1 == size)
            {
              
                return false;
            }
        }
        else
        {
            //���� ������� ��� �� ������ �������� != 0, �� ����������� �� ������������ ������� �� ��������� ���� ������� ������� ������

           it2 = indexArr[it2 - 1];

        }
           
    }
    return false;
}
void UnitTest()
{
    const int size = 8;
    char* str1 = new char [size] {"zxcvbnm"}; //1
    char* str2 = new char [size] {"nmzxcvb"};
    cout << endl << checkingAlg(str1, str2, size - 1) << endl;

    str1 = new char [size] {"zxcvbnm"}; //0
    str2 = new char [size] {"gnmzcvb"};
    cout << endl << checkingAlg(str1, str2, size - 1) << endl;


    str1 = new char [4] {"abc"}; //1
    str2 = new char [4] {"cab"};
    cout << endl << checkingAlg(str1, str2, 3) << endl;

    str1 = new char [5] {"qwer"}; //1
    str2 = new char [5] {"rqwe"};
    cout << endl << checkingAlg(str1, str2, 4) << endl;

    str1 = new char [5] {"qwer"}; //1
    str2 = new char [5] {"rqwe"};
    cout << endl << checkingAlg(str1, str2, 4) << endl;

    str1 = new char [5] {"�wer"}; //0
    str2 = new char [5] {"����"};
    cout << endl << checkingAlg(str1, str2, 4) << endl;

    str1 = new char [5] {"�ggg"}; //0
    str2 = new char [5] {"rqwe"};
    cout << endl << checkingAlg(str1, str2, 4) << endl;

    str1 = new char [3] {"ab"}; //1
    str2 = new char [3] {"ba"};
    cout << endl << checkingAlg(str1, str2, 2) << endl;


    str1 = new char [3] {"ab"}; //1
    str2 = new char [3] {"ba"};
    cout << endl << checkingAlg(str1, str2, 2) << endl;

    str1 = new char [7] {"qwerty"}; //1
    str2 = new char [7] {"yqwert"};
    cout << endl << checkingAlg(str1, str2, 6) << endl;

    str1 = new char [23] {"aaaaaaaaaaaaaaaaaaabab"}; //1
    str2 = new char [23] {"abaaaaaaaaaaaaaaaaaaab"};
    cout << endl << checkingAlg(str1, str2, 22) << endl;
}
int main()
{
    const int size = 8;
    char *str1 = new char [size]  { "zxcvbnm" };
    char *str2= new char [size]  { "mzxcvbn" };
    UnitTest();
    cout <<endl<< checkingAlg(str1, str2, size - 1) << endl;
}
