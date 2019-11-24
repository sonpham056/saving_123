#pragma warning(disable : 4996)
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
int search(int a[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int binarySearch(int a[], int n, int key)
{
	int LEFT, RIGHT, MID;
	LEFT = 0;
	RIGHT = n - 1;
	while (LEFT <= RIGHT)
	{
		MID = (LEFT + RIGHT) / 2;
		if (a[MID] == key)
			return MID;
		if (a[MID] > key)
			RIGHT = MID - 1;
		else
			LEFT = MID + 1;
	}
	return -1;
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
	}
}
void selectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int locMin = i;
		for (int j = i + 1; j < n; j++)
			if(a[j] < a[locMin])
				locMin = j;
		swap(a[locMin], a[i]);
	}
}
void insertionSort(int a[], int n)
{
	int pos, x;
	for (int i = 0; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
void Menu()
{
	cout << "-----------------------\n";
	cout << "Input a number to run!";
	cout << "\n1. File output";
	cout << "\n2. Search";
	cout << "\n3. Binary Search";
	cout << "\n4. interchange Sort";
	cout << "\n5. Bubble Sort";
	cout << "\n6. selection Sort";
	cout << "\n7. insertion Sort";
	cout << "\nPress ENTER to exit!\n";
}
int main()
{
	clock_t t1, t2;
	double tg;
	int a[100001], n, key, kq;
	FILE* f;
	f = fopen("D:\\Hoctap\\CTDL_va_GT\\data005.in", "r");
	if (f == NULL)
		cout << "Shit";
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &a[i]);
	}
	fclose(f);
	Menu();
	char temp = _getch();
	while (temp != 13)
	{
		cout << "inputted number: " << (int)temp - 48 << endl;
		switch (temp)
		{
		case '1':
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			break;
		case '2':
			cout << "\nNhap so can tim: ";
			cin >> key;
			kq = search(a, n, key);
			if (kq != -1)
				cout << "Vi tri cua so can tim la: " << kq;
			else
				cout << "Error! Khong tim thay";
			break;
		case '3':
			cout << "\nNhap so can tim: ";
			cin >> key;
			kq = binarySearch(a, n, key);
			if (kq != -1)
				cout << "Vi tri cua so can tim la: " << kq;
			else
				cout << "Error! Khong tim thay";
			break;
		case '4':
			t1 = clock();
			interchangeSort(a, n);
			t2 = clock();
			tg = (double)(t2 - t1) / CLOCKS_PER_SEC;
			cout << "interchange Sort TIME: " << tg << endl;
			break;
		case'5':
			t1 = clock();
			bubbleSort(a, n);
			t2 = clock();
			tg = (double)(t2 - t1) / CLOCKS_PER_SEC;
			cout << "Bubble Sort TIME: " << tg << endl;
			break;
		case'6':
			t1 = clock();
			selectionSort(a, n);
			t2 = clock();
			tg = (double)(t2 - t1) / CLOCKS_PER_SEC;
			cout << "selection Sort TIME: " << tg << endl;
			break;
		case'7':
			t1 = clock();
			insertionSort(a, n);
			t2 = clock();
			tg = (double)(t2 - t1) / CLOCKS_PER_SEC;
			cout << "insertion Sort TIME: " << tg << endl;
			break;
		default:
			cout << "INPUT THE RIGHT NUMBER YOU IDIOT!";
		}
		cout << "\n";
		Menu();
		temp = _getch();
	}
	return 0;
}