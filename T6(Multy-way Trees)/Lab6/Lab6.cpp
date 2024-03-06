// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int nr = 9;
struct arb_multicai {
		int cheie;
		int nr_copii=0;
		arb_multicai *copii[20];
}* v_multi[100],*rad;
void print_R1(int R1_parinte[20],int el, int nrdecalaj){//afisez din r1, recursiv, fii care decaleaza, initial apelez cu -1
	int i, j;
	for(i=1;i<=nr;i++)
		if(R1_parinte[i]==el){
			std::cout<<endl;
			for(j=0;j<nrdecalaj;j++)
				std::cout<<"   ";
			std::cout<<i;
			print_R1(R1_parinte,i,nrdecalaj+1);
		}

}


int main()
{
	int R1_parinte[] = {0, 2, 7, 5, 2, 7, 7, -1, 5, 2, 9, 9 };
	int i;
	int copii[20];
	std::cout << "Pretty print for R1" << endl;
	print_R1(R1_parinte,-1, 0);
	
	
	
   
}
