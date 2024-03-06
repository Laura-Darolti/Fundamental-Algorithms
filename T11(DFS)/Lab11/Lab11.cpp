// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int time1 = 0;
/*typedef struct Node {
    int key;
    Node* parent;
    int color;//0=white,1=gray,2=black;
    int dist;
};
struct Point {
    int row;
    int col;
};
typedef struct _Node {
   // Point position;
    int key;
    int adjSize=0;
   // struct _Node** adj;
    int color;//0=white,1=gray,2=black;
    int dist;
    struct _Node* parent;
    int f;
}Node;
typedef struct Graph{
    int nrNodes;//nr varfuri
   // Node** v;
    Node* vect_vecini[10];
}vect_chei[20];
Graph graph;*/
typedef struct node
{
    int key;
    struct node* parent;
    int dist;
    int color;
    int f;

}Node;
Node* AddElementInFataLista(Node* first, int x) {
    Node* nou;
    nou = (Node*)malloc(sizeof(node));
    nou->key = x;
    nou->parent = first;
    return nou;
}
int nr_vecini[5];
void dfs_visit(Node* u, Node* noduri[], Node* liste_vecini[]) {
    Node* v;
    int i;
    time1++;
    u->dist = time1;
    u->color = 1;
    //for (int i = 0; i < nr_vecini[i]; i++)
    v = liste_vecini[u->key];
    do {
        if (v->color == 0)
        {
            v->parent = u;
            dfs_visit(v, noduri, liste_vecini);
        }
        v = v->parent;
    } while (v != NULL);
    u->color = 2;
    time1++;
    u->f = time1;

}

void dfs(Node* noduri[], Node* liste_vecini[]) {
    for (int i = 0; i < 5; i++)
    {
        noduri[i]->color = 0;
        noduri[i]->parent = NULL;

    }
    time1 = 0;
    for (int i = 0; i < 5; i++)
        if (noduri[i]->color == 0)
            dfs_visit(noduri[i], noduri, liste_vecini);
}
void afisare(node* first) {
    node* p;
    for (p = first; p != NULL; p = p->parent)
        cout << "->" << p->key;
    cout << endl;
}
void Print_R2(Node* p, int nrdecalaj, Node* liste_vecini[]) {
    if (p == NULL)
        return;
    cout << endl;
    int j;
    for (j = 0; j < nrdecalaj; j++)
        cout << "   ";
    cout << p->key << " " << p->color;
    for (j = 0; j < nr_vecini[j]; j++)
        Print_R2(liste_vecini[j], nrdecalaj + 1, liste_vecini);
}
int main()
{
    int i, j;
    Node* liste_vecini[5], * noduri[5];
    //liste_vecini[5] = (Node*)malloc(5 * sizeof(Node*));
    //noduri[5] = (Node*)malloc(5 * sizeof(Node*));

    liste_vecini[0] = NULL;
    liste_vecini[0] = AddElementInFataLista(liste_vecini[0], 1);
    liste_vecini[0] = AddElementInFataLista(liste_vecini[0], 2);
    liste_vecini[1] = NULL;
    nr_vecini[0] = 2;

    liste_vecini[1] = AddElementInFataLista(liste_vecini[1], 0);
    liste_vecini[1] = AddElementInFataLista(liste_vecini[1], 3);
    nr_vecini[1] = 2;
    liste_vecini[2] = NULL;

    liste_vecini[2] = AddElementInFataLista(liste_vecini[2], 0);
    liste_vecini[2] = AddElementInFataLista(liste_vecini[2], 3);
    nr_vecini[2] = 2;
    liste_vecini[3] = NULL;
    liste_vecini[3] = AddElementInFataLista(liste_vecini[3], 1);
    liste_vecini[3] = AddElementInFataLista(liste_vecini[3], 2);
    liste_vecini[3] = AddElementInFataLista(liste_vecini[3], 4);
    nr_vecini[3] = 3;
    liste_vecini[4] = NULL;
    liste_vecini[4] = AddElementInFataLista(liste_vecini[4], 3);
    nr_vecini[4] = 1;
    for (i = 0; i < 5; i++)
        noduri[i]->key = i;
    dfs(noduri, liste_vecini);
    for (i = 0; i < 5; i++)
        afisare(liste_vecini[i]);
}
   