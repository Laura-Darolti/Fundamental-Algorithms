// Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<time.h>
#define _N_ 11
using namespace std;
struct node {//structura arborelui binar
    int key = 0;
    node* left;
    node* right;
    node* p;
    long size = 0;
}*z, * y, * x;
node* rad = NULL;
int afisrec = 0,afisit=0,atr=0,comp=0,comp1=0,atr1=0;
node* stack[_N_]= {};
long top = 0;

void Tree_insert(long key)//functia de inserare a unui element in arbore binar de cautare,
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
void ConstruiesteEchilibrat(long v[], long n, long stanga, long dreapta)//apelez cu stanga=1 si dreapta=n(de unde pana unde am de echilibrat)
{
    if (dreapta >= stanga)//cand nu se mai indeplineste conditia inseamna ca am terminat,am echilibrat arborele
    {
        long mijloc = (dreapta + stanga) / 2;
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
void Preordine(node* p) {//recursiv

    if (p != NULL) {
        
        
        afisrec++;
        cout << p->key << " ";
        Preordine(p->left);
        Preordine(p->right);
        

    }

}
int isempty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (top == _N_)
        return 1;
    else
        return 0;
}
void push(node* p)
{
    if (isfull())
        return;
    top = top + 1;
    stack[top] = p;
}
node *pop()
{
    if (top == 0)
        return 0;
    else
        top = top - 1;
    return stack[top + 1];

}
void iterativePreorder(node* rad)
{
    node* curent = rad;
    while (isempty() == 0 || curent != NULL)
    {
        if (curent != NULL)
        {
            cout << curent->key << " ";
            afisit++;
            if (curent->right != NULL)
                push(curent->right);
            curent = curent->left;
        }
        else
            curent = pop();        

    }
}

int main()
{
    long n = 100;
    long a[_N_+1],b[_N_ + 1];
    long v[_N_ + 1];
    
    for (long i = 1; i <= _N_; i++)
    {
        v[i] = i;
    }

    ConstruiesteEchilibrat(v, _N_, 1, _N_);
    Preordine(rad);
    cout << endl;
    iterativePreorder(rad);
    cout<<endl<< " afisari recursiv  " << afisrec << " afisari iterativ  "<<afisit<<endl;

  

    

    
}


