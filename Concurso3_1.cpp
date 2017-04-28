/*
 * Concurso3_1.cpp
 *
 *  Created on: Apr 27, 2017
 *      Author: marga
 */

#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;





int reverseNumber(int number){
	int u, d, c, reversed;
	if (number >=100){
	u = (number - (number%100))/100;
	c = (number%10)*100;
	d = ((number%100)-(c/100));
	 reversed = c+d+u;
	}
	else if (number <100 && number >=10){
		c = 0;
		d = (number%10)*10;
		u = (number-(number%10))/10;
		reversed = c + d + u;
	}

	else reversed = number;

	return reversed;

}


int main(){
	int T;
	cin>>T;
	int counters [T];
	int Ns [T];

	for (int i = 0; i<T; i++){
		int N;
		cin>>N;
		Ns[i] = N;

	}

	for (int i = 0; i < T; i++){

		int temp = 0;
		int count = 0;
		while(temp < Ns[i]){
			int auxTemp= reverseNumber(temp);
			if(auxTemp > temp && auxTemp <= Ns[i])
				temp =auxTemp;

			else
				temp ++;


			count ++;

		}
		cout << "Case #" << i+1 << ": " <<count << endl;

	}

	//for (int i = 0; i< T; i++)
	//	cout << "Case #" << i+1 << ": " <<counters[i] << endl;


}
