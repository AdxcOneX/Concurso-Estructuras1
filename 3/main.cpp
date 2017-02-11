#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <fstream>  


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	float input = 0;
	int count = 0;
	int max = 0;
	map<float, int> heights;
	
	/*
	ifstream file("input.txt");
    while (getline(file, count))
    {
    	cout << count;
    }
	*/
	cin>>input;
	max = input;
	while(max >= 3 && max <= 400){
		cin>>input;
		while(input != 0 && input > 0.5 && input < 2.5){
			input = roundf(input * 100) / 100;
			heights[input]++;
			//cout << heights[input];
			if(++count == max){
				break;
			}
			cin>>input;	
		}
	
		float valueMean1=0;
		float valueMean2=0;
		int freqMean1=0;
		int freqMean2=0;
	
		map<float, int>::iterator ite = heights.begin();
		pair<float, int> firstHeight = *ite;
		valueMean1 = firstHeight.first;
		freqMean1 = firstHeight.second;
		ite++;
		
		while(ite != heights.end()){
			pair<float, int> current = *ite;
			if(current.second > freqMean1){
				freqMean2 = freqMean1;
				valueMean2 = valueMean1;
				freqMean1 = current.second;
				valueMean1 = current.first;
			}else if(current.second > freqMean2){
				freqMean2 = current.second;
				valueMean2 = current.first;
			}
			ite ++;
		}
		
		printf("First: %.2f -> %d. Second: %.2f -> %d.", valueMean1, freqMean1, valueMean2, freqMean2);
		cin>>input;
		max = input;
		count = 0;
	}

	return 0;
}
