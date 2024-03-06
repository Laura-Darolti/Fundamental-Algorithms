// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<time.h>
#define _N_ 11
using namespace std;
struct set {
    int key=0;
    struct set* p;
    int rank=0;
};
set *x= NULL;
struct muchie {
    set* sursa;
    set* dest;
    int pond;
}*v_muchii[20];
void Make_set(set*x,int key) {
    
    x->p = x;
    x->rank = 0;
    x->key = key;


}
void Link(set* x, set* y)
{
    if (x->rank > y->rank)
        y->p = x;
    else
    {
        x->p = y;
        if (x->rank == y->rank)
            y->rank = y->rank + 1;
    }

}
set* Find_set(set *x) {
    if (x != x->p)
        x->p = Find_set(x->p);
    return x->p;

}
void Union(set* x, set* y)
{
       if (Find_set(x) != Find_set(y))
            Link(Find_set(x), Find_set(y));
}
set* a, * b, * c, * d,*e;
void print(set* x)
{
    set* nod = x;
    while (nod != NULL)
    {
        cout << nod->key << " ";
        nod = nod->p;
    }
    nod = x;
}


int main()
    {
    a = (set*)malloc(sizeof(set));
    b = (set*)malloc(sizeof(set));
    c = (set*)malloc(sizeof(set));
    d = (set*)malloc(sizeof(set));
    e = (set*)malloc(sizeof(set));
    //char aa='A', bb='B', cc='C', dd='D', ee='E';
    Make_set(a,1);
    Make_set(b,2);
    Make_set(c,3);
    Make_set(d,4);
    Make_set(e,5);
    Union(a, b);
    Union(a, c);
    Union(b, c);
    Union(a, d);
    Union(a, e);
            

    cout << Find_set(a)->key<<" "<<Find_set(b)->key<<" "<< Find_set(c)->key <<" "<< Find_set(d)->key<<" "<<Find_set(e)->key;
    print(x);

    
}

