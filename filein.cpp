#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int cows_num;
	srand((int)time(NULL));
	
	//open the file stores the generated data
	ofstream outFile("filein.txt",ios::out);
	if(!outFile) {
		cerr << "Failed opening" << endl;
		exit(1);
	}
	
	//input the number of cows
	cin >> cows_num;
	outFile << cows_num << "\n";
	
	//randomly generate data and output to file
	for(int i=0 ; i<cows_num ; ++i){
		outFile << rand()%1000+300 << "\n";
	}
	
	return 0;
}
