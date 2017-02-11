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
	string cadena [];
	string cadenaO [];
	string temp;
	cin >> T;
	for(int i=0; i>T; i++){
		 for(int C = 1; C < N; C++){
			 for(int CO = 0; CO < N; CO++){
				 if(cadena[C]==cadenaO[CO]){
					 if (C!=CO){
						 temp = cadena[C];
						 cadena[C] = cadena[CO];
						 cadena[CO] = temp;
					 }
				 }
			 }
		 }
	}

}
