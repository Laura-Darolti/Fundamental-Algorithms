#include <cstdlib>
#include <fstream>
#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
#include <iostream>
#include<cstring>
using namespace std;

typedef struct h_item {
    char name[30];
    int id;
};

const int sizetable = 9973;
float loadFactor = 0.95,rezultat;

h_item table[sizetable];
int comp = 0, atr = 0;

int  hash_function(int id, int i) {
   // return (id + i + i * i) % sizetable;
    return (id+i*i) % sizetable;
}
int hash_insert(h_item table[sizetable], int id) {
    int i = 0, j;
    do {
        j = hash_function(id, i);
        if (table[j].id == -1) {
            table[j].id = id;
            return j;
        }
        else
            i++;
    } while (i != sizetable);
    return -1;
}
int hash_search(h_item table[sizetable], int id) {
    int i = 0, j;
    do {
        j = hash_function(id, i);
        atr++;
        comp++;
        if (table[j].id == id)
            return j;
        i++;
        
    } while (table[j].id != -1 && i != sizetable);
    return -1;
}
int hash_delete(h_item[sizetable], int id) {
    int i = 0, j;
    j = hash_search(table, id);
    if (j >= 0) {
        table[j].id = -1;
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    //long m = (loadFactor * sizetable) / 2;
    int i, n = 0, PanaLa = sizetable * 10,sum_gasit=0,sum_negasit=0,max_gasit=-1,max_negasit=-1, succ=0;
    int Adaugate[sizetable];
    for (int i = 0; i < sizetable; i++) {
        table[i].id = -1;
        Adaugate[i] = -1;
    }
    long j;
    int gasite = 0, negasite = 0;
    for (int i = 0; i < loadFactor * sizetable; i++) {
        j = rand() % PanaLa;
       
       succ= hash_insert(table, j);
       if (succ > -1) {
           Adaugate[n] = j;
           n++;
       }
        
    }
   /* for (int i = 0; i < loadFactor * sizetable; i++)
        cout << table[i].id << " ";*/
    long m = 0;
    do {
        j = rand() % n;
        m++;
        comp = 0;
        if (hash_search(table, Adaugate[j]) != -1)
        {
            gasite++;
            if (comp > max_gasit)
                max_gasit = comp;
            sum_gasit += comp;
        }

        else
            negasite++;
        j = PanaLa + rand() % PanaLa;
        m++;
        comp = 0;
        if (hash_search(table, j) != -1)
            gasite++;
        else {
            negasite++;
            if (comp > max_gasit)
                max_negasit = comp;
            sum_negasit += comp;
        }
            
    } while ((gasite + negasite) < 3000 || abs(gasite - negasite) > 100);
    
    cout << endl << "au fost " << atr << " atribuiri, " << comp << " comparari cu " << gasite << " gasite si " << negasite << " negasite";
    cout << endl << "efort med gasite " << sum_gasit/gasite << ", ef max gasite " << max_gasit;
    cout << endl << "efort med negasite " << float(sum_negasit / negasite) << ", ef max negasite " << max_negasit;

    //umplere pana la 0.99
    while (n < 0.99 * sizetable) {
        j = rand() % PanaLa;
        succ=hash_insert(table, j);
        if (succ > -1) {
            Adaugate[n] = j;
            n++;
        }
    }
    cout << endl << "umplut pana la 0.99%";
   /* for (int i = 0; i < 0.99 * sizetable; i++)
        cout << table[i].id << " ";
    cout << endl;*/
    // ca sa nu caut elementele sterse si readunate salvez elementele din lista

    //golit pana la 0.8 %
    while (n > 0.8 * sizetable) {
      
        hash_delete(table, Adaugate[n-1]);
        n--;
    }
    cout << endl << "golit pana la 0.8%";
  /*  for (int i = 0; i < sizetable; i++)
        cout << table[i].id << " ";
    cout << endl;*/


    atr = 0, comp = 0, gasite = 0, negasite = 0;
    do {
        j = rand() % n;
        m++;
        comp = 0;
        if (hash_search(table, Adaugate[j]) != -1)
        {
            gasite++;
            if (comp > max_gasit)
                max_gasit = comp;
            sum_gasit += comp;
        }

        else
            negasite++;
        j = PanaLa + rand() % PanaLa;
        m++;
        comp = 0;
        if (hash_search(table, j) != -1)
            gasite++;
        else {
            negasite++;
            if (comp > max_gasit)
                max_negasit = comp;
            sum_negasit += comp;
        }

    } while ((gasite + negasite) < 3000 || abs(gasite - negasite) > 1000);
    cout << endl << "au fost " << atr << " atribuiri, " << comp << " comparari cu " << gasite << " gasite si " << negasite << " negasite";
    cout << endl << "efort med gasite " << sum_gasit / gasite << ", ef max gasite " << max_gasit;
    cout << endl << "efort med negasite " << sum_negasit / negasite << ", ef max negasite " << max_negasit;

}