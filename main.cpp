#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Clock.h"
using namespace std;

void insertion_sort(vector<int> & v){
	int insert, moveItem;

	for(int next=1;next<v.size();++next){
		insert = v.at(next);
		moveItem = next;
		
		while((moveItem>0) &&(v.at(moveItem-1) > insert)){
			v.at(moveItem) = v.at(moveItem-1);
			--moveItem;
		}
		
		v.at(moveItem) = insert;
	}
}

int main(){
	int v_size,weight;
	Clock clk;
	
	ifstream inFile("filein.txt", ios::in);
	if(!inFile){
		cerr << "Failed opening" << endl;
		exit(1);
	}
	
	inFile >> v_size;
	vector<int> cows_weight(v_size),insertsort_cows_weight;
	
	//assign value
	for( int i=0 ; i<v_size ; ++i ){
		inFile >> weight;
		cows_weight.at(i) = weight;
	}
	insertsort_cows_weight = cows_weight;
	
	//sort and count down
	clk.start();
	insertion_sort(insertsort_cows_weight);
	cout << "insert_sort(): " << clk.getElapsedTime() << 
		" seconds\n";

	clk.start();
	sort(cows_weight.begin(),cows_weight.end());
	cout << "sort(): " << clk.getElapsedTime() << " seconds\n";
	
	//print the largest weight
	cout << cows_weight[v_size-1] << endl;	
	return 0;
}