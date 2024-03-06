#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>

using namespace std;
ofstream rez("size.txt");
void generez_aleat(long long a[10000], long long n)/*functia prin care generez un sir aleatoriu*/
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 99 + 1;
    }
}
typedef struct nodetype
{
    int data;
    struct nodetype* next;
}node;


void heapifyMin(long long arr[], int n, int i) {
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    if (l < n && arr[l] < arr[smallest])// If left child is smaller than root
        smallest = l;
    if (r < n && arr[r] < arr[smallest])// If right child is smaller than smallest so far
        smallest = r;
    if (smallest != i) { // If smallest is not root
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);// Recursively heapify the affected sub-tree
    }
}
void heapSortDesc(long long arr[], int n) {//heap_min
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
   /* for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }*/
}
void printArray(long long arr[], int n) {
    for (int i = 0; i < n; ++i)
        rez << arr[i] << " ";
    rez << "\n";
}



node* AddElementInLista(node* first, int x)
{
    node* nou;
    nou = (node*)malloc(sizeof(node));
    nou->data = x;
    nou->next = NULL;

    if (first == NULL) {
        first = nou;
        return first;
    }
    else
    {
        if (first->data >= x) {//inserat in fata
            nou->next = first;
            first = nou;
            return first;
        }
        node* p1 = first, * p2 = first->next;

        while (p2 != NULL && p2->data < x) {
            p2 = p2->next;
            p1 = p1->next;
        }
        if (p2 == NULL) {// a avut un singur element
            p1->next = nou;
            return first;
        }
        else {
            nou->next = p2;
            p1->next = nou;
        }
        return first;
    }
}
node* AddElementInFataLista(node* first, int x) {
    node* nou;
    nou = (node*)malloc(sizeof(node));
    nou->data = x;
    nou->next = first;
    return nou;
}


void afisare(node* first) {
    node* p;
    for (p = first; p != NULL; p = p->next)
        cout << "->" << p->data;
    cout << endl;
}



int main() {
    long long a[10000];
    long n = 20, k = 3;// k subsiruri, n numere
    node* ksir[3];//cat este k
    int m[3];//numarul de element din fiecare subsir din k
    int i;
    //, j,size,size2,k,p,m;
    srand(time(NULL));
    generez_aleat(a, n);
    cout << endl << "elementele gennerate pentru n= " << n << endl;
    printArray(a, n);


    int ramase = n;
    int kk = 0;
    i = 0;
    do {
        ksir[kk] = NULL;
        if (kk == k - 1)
            m[kk] = ramase;
        else
            m[kk] = (1 + rand()) % ramase; //nu e asigurat minumum un element, deci la final initializez listele goale
        //m[kk] = (1 + rand()) % (ramase- (k-1-kk)); //asigura minumum un element

        cout << endl << "k" << kk + 1 << " are " << m[kk] << "  elemente" << endl;
        heapSortDesc(a + i, m[kk]); //daca se ordoneaza descrescator si se adauga in fata va fi crescator
        for (int p = i; p < i + m[kk]; p++) {
            ksir[kk]=AddElementInLista(ksir[kk],a[p]);
           // ksir[kk] = AddElementInFataLista(ksir[kk], a[p]);
        }
        afisare(ksir[kk]);

        i += m[kk];
        ramase = ramase - m[kk];
        kk++;
    } while (ramase != 0);
    while (kk < (k - 1)) {
        ksir[kk] = NULL;
        m[kk] = 0;
        kk++;
    }

    cout << endl << "SUBSIRURILE:" << endl;
    for (int i = 0; i < k; i++) {
        cout << endl << "Sirul:" << i + 1 << endl;
        afisare(ksir[i]);

    }

    cout << endl;
    printArray(a, n);
}