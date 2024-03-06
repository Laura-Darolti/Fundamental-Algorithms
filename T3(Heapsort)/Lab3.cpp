// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;
ofstream g("output.txt");
ofstream rez("output1.txt");
int comp1=0, comp2=0, comp3=0, atr1=0, atr2= 0;
long long n = 500;
void generez_aleat(long long a[10000], long long n)/*functia prin care generez un sir aleatoriu*/
{
	
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 99 + 1;
	}


}
void swap(int x, int y)
{
	int aux;
	aux = x;
	x = y;
	y = aux;

}
long Partition(long long a[10000], int p, int r)
{
	int x, i,j;
	x = a[r];
	i = p-1;
	for (j = p; j <=r - 1; j++)
	{comp1++;
	comp2++;
		if (a[j] <= x)
		{
	
			i++;
			swap(a[i], a[j]);
			atr1 += 3;
			atr2 += 3;
			
		}
		
	}
	swap(a[i + 1], a[r]);
	atr1+=3;
	atr2 += 3;
	return i + 1;

}
long random_partition(long long a[10000], int p, int r)
{
	srand(time(NULL));
	int i;
	i = p+rand()%(r-p);
	swap(a[r], a[i]);
	atr2+=3;
	return Partition(a, p, r);

}
void random_quicksort(long long a[10000], int p, int r)
{
	int q;
	comp2++;
	if (p < r)
	{
		q = random_partition(a, p, r);
		random_quicksort(a, p, q - 1);
		random_quicksort(a, q + 1, r);
	}

}
void quicksort(long long a[10000], int p, int r)
{
	int q;
	comp1++;
	if (p < r)
	{
		atr1++;
		q = Partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}

}

int main()
{
	int p, r;
	long long a[10000], b[10000];
	/*worst case*/	
	/*long long c[] = {0,1,2,3,4,5,6,7,8,9,10};
	quicksort(c, 0, 10);
	rez << atr1 << ' '<<comp1 <<" " <<atr1 + comp1;
	for (int i = 0; i < 11; i++)
		g << c[i];
		generez_aleat(a, n);
		for (int i = 0; i < n; i++)
		{
			b[i] = a[i];
			g << a[i] << " ";
		}
		g << endl;*/
		for (int i = 100; i <= 10000; i += 500)
		{
			generez_aleat(a, i);
			quicksort(a, 0, i);
			rez << atr1 << " " << comp1 << " " << atr1 + comp1;
			rez << endl;
			atr1 = 0;
			comp1 = 0;
		}


		/*quicksort(a, 0, n - 1);
		for (int i = 0; i < n; i++)
			g << a[i] << " ";
		g << endl;
		rez << atr2 << " " << comp2 << " "<<" "<<atr2+comp2;

		
		for (int i = 0; i < n; i++)
			g << b[i] << " ";
		g << endl;
		random_quicksort(b, 0, n - 1);
		for (int i = 0; i < n; i++)
			g << b[i] << " ";
		rez << endl;
		rez << atr1 << " " << comp1 << " " << atr1 + comp1;*/
	
	



   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
