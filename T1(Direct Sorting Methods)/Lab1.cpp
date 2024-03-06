// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;
int atr, comp;/*variabilele pe care le folosesc pt a determina nr de atribuiri si comparatii din alg de sortare*/
ofstream g("output.txt");
void insertsort (long long n, long long A[10000])
{
    int j,i,x;
    for (i = 1; i < n; i++)
    {
        x = A[i];
        
        j = i - 1;
        while (j >= 0 && A[j] > x)
        {
            comp++;
            A[j + 1] = A[j];
            atr++;
            j--;
            
        }
        A[j + 1] = x;
        atr++;
    }
   


}
void afis(long long  n, long long  A[10000])
{
    for (int i = 0; i < n; i++)
        g << A[i] << " ";
}
void generez_aleat(long long n, long long A[10000])/*functia prin care generez un sir aleatoriu,pentru a putea analiza cazul average*/
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }


}
void swap(int x, int y)
{
    int aux;
    aux = x;
    x = y;
    y = aux;

}

int main()
{
    long long  A[10000],n;
    cin >> n;/*alaeg pe rand nr de elemente pt fiecare sir,variind de la 100 la 500 pt 5 masuratori*/
    int i,suma=0;
    generez_aleat(n, A);
    for (i = 0; i < n; i++)
        g<< A[i] << " ";

    g << endl;

    
    insertsort(n, A);
    afis(n, A);
    g << endl;
    g << atr << " " << comp<<" ";/*dupa fiecare rulare,salvez valorile pt atr,comp si suma pentru a putea genera graficele*/
    suma = atr + comp;
    g << suma;
    return 0;
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
