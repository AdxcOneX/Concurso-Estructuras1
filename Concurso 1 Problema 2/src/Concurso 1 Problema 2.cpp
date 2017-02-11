//============================================================================
// Name        : Concurso.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int N;
	string cadena [100]={"B", "C", "A", "D", "F", "E"};
	string cadenaO [100]{"A", "B", "C", "D", "E", "F"};
	string temp;
	string cambios [100];
	int j=0;
	cin >> T;
	for(int i=0; i>T; i++){
		cin >> N;
		 for(int C = 1; C < N; C++){
			 for(int CO = 0; CO < N; CO++){
				 if(cadena[C]==cadenaO[CO]){
					 if (C!=CO){
						 cambios[j] = cadena[C];
						 j++;
						 temp = cadena[C];
						 cadena[C] = cadena[CO];
						 cadena[CO] = temp;
					 }
				 }
			 }
		 }
	}
	cout << cambios[0];
	cout << cambios[1];

}
