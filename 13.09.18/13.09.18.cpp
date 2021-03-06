// 13.09.18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;
void delete_arr(int** &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}
void erase_last_column(int** a, int n, int &m)
{
	m--;//удаление последней колонки
}
void erase_1st_column(int** a, int n, int &m)
{
	for (int i = 0; i < n; i++) //удаление первой колонки
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = a[i][j + 1];
		}
	}
	m--;
}
void erase_k_column(int** a, int n, int &m, int k)
{
	cin >> k; //удаление конкретного столбца

	for (int i = 0; i < n; i++)
	{
		for (int j = k; j < m; j++)
		{
			a[i][j] = a[i][j + 1];
		}
	}
	m--;
}
void add_1st_column(int** &a, int n, int &m)
{
	int** tmp; //добавление первого столбца
	tmp = new int*[n];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = new int[m + 1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j + 1] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = tmp;
	m++;
}
void add_new_column(int** &a, int n, int &m, int k)
{
	cin >> k; //добавление конкретного столбца

	int** tmp;
	tmp = new int*[n];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = new int[m + 1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j < k)
				tmp[i][j] = a[i][j];
			else
				tmp[i][j + 1] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = tmp;
	m++;

}
void fill_matrix(int** a, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			/*a[i][j] = rand() % 10;
			cout << setw(4) << a[i][j];*/
		}
		
	}
}
void check(int **arr,int  m, int n) // Магический квадрат мой вариант?
{
	int sum1 = 0, sum2 = 0, DYAG1 = 0, DYAG2 = 0;
	for (int i = 0; i < 3; i++)
	{
		sum1 = 0;
		for (int j = 0; j < 3; j++)
		{
			sum1 += arr[i][j];
		}
	}

	for (int t = 0; t<3; t++) 
	{
		sum2 = 0;
		for (int j = 0; j<3; j++) 
		{
			sum2 += arr[t][j];
		}
	}

	for (int p = 0, j = 0; p<3; p++, j++)
	{
		DYAG1 += arr[p][j];
	}
		
	for (int g = 0, k = 3 - 1; k >= 0; g++, k--) 
	{
		DYAG2 += arr[g][k];
	}

	cout << sum1 << endl;
	cout << sum2 << endl;
	cout << DYAG1 << endl;
	cout << DYAG2 << endl;
		
	int CONTROL = sum1;
	
	if ((sum2==CONTROL) && (DYAG1 == CONTROL) && (DYAG2 == CONTROL))
	{
		cout << "Magic Matrix" << endl;
	}
	else
	{
		cout << "NO!" << endl;
	}
}

bool magic_square(int** a, int n) // Магическая матрица проверка <---------ЭТО ВАРИАНТ АКБАЯН
{
	int sum = 0;
	int magic_value = 0;
	for (int i = 0; i < n; i++)
	{
		magic_value += a[0][i];		
	}
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += a[i][j];
		}
		if (sum != magic_value) return false;
	}
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += a[j][i];			
		}
		if (sum != magic_value) return false;
	}
	
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i][n - 1 - i];		
	}
	if (sum != magic_value) return false;
	return true;
	
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n , m  ;
	int** arr;
	cin >> n >> m;
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	
	fill_matrix(arr, n, m);
	
	//check(arr,n,m);
	cout<<magic_square(arr,n);
	
	//delete_arr(arr, n);

	/*int** arr;
	int n = 3, m = 3;
	int k = 0;
	arr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	fill_matrix(arr, n, m);
	check(arr, n, m);*/
	/*erase_1st_column(arr, n, m);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	erase_last_column(arr, n, m);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	erase_k_column(arr, n, m, k);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}*/
	/*add_1st_column(arr, n, m);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}*/

	/*add_new_column(arr, n, m, k);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}

	delete_arr(arr, n);*/


	system("pause");
	return 0;
}

