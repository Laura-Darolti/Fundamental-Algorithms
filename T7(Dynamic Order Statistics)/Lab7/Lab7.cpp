// Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
using namespace std;
ofstream g("output.txt");
struct node {//structura arborelui binar
    int key=0;
    node* left;
     node* right;
    node* p;
    int size=0;
}*z,*y,*x;
node* rad = NULL;

void Tree_insert(int key)//functia de inserare a unui element in arbore binar de cautare,
//fii din stanga for fi intotdeauna mai mici decat cei din dreapta;

{
    z = (node*)malloc(sizeof(node));//aloc memorie noului nod inserat si initializez campurile ;
    z->left = z->right = NULL;
    z->key = key;
    z->size = 1;
    y = NULL;
    x = rad;
    while (x != NULL)
    {
        x->size++;
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (y == NULL)//daca arborele a fost vid
        rad = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}
void ConstruiesteEchilibrat(int v[], int n, int stanga, int dreapta)//apelez cu stanga=1 si dreapta=n(de unde pana unde am de echilibrat)
{
    if (dreapta >= stanga)//cand nu se mai indeplineste conditia inseamna ca am terminat,am echilibrat arborele
    {
        int mijloc = (dreapta + stanga) / 2;
        if (dreapta - stanga == 1)//daca am doua numere consecutive inserez pur si simplu cele doua in stanga respectiv dreapta;
        {
            Tree_insert(v[stanga]);
            Tree_insert(v[dreapta]);
        }
        else
        {
            if (dreapta == stanga)
                Tree_insert(v[stanga]);
            else
            {
                Tree_insert(v[mijloc]);//inserez mijlocul si apelez functia recursiv pe cele doua parti(inainte si dupa mijloc)
                ConstruiesteEchilibrat(v, n, stanga, mijloc - 1);
                ConstruiesteEchilibrat(v, n, mijloc + 1, dreapta);
            }
        }
    }
}

void print2(node* nod, int space)
{
    int count = 6;
    if (nod == NULL)
        return;
    space += count;
    cout << endl;
    for (int i = count; i < space; i++)
        cout << " ";
    cout << nod->key << "  size: " << nod->size << endl;
    print2(nod->left, space);
    print2(nod->right, space);
}
/*node* Os_select(node* x, int i) {
   
    int r = x->left->size + 1;
    if (i == r)
        return x;
    else
        if (i < r)
            return Os_select(x->left, i);
        else
            return Os_select(x->right, i - r);

}*/


int main()
{
    
    int n = 11;
    int v[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
   
    int j ,i;
    ConstruiesteEchilibrat(v, n, 1, n);
    print2(rad, 0);
    
    
    
}


