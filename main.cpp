#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

int main(int argc, char ** argv){
	if (argc < 2){
		cout << "command line" << endl;
	} else {
		string fileName = argv[1];
		ifstream file(fileName);
		string line;
		vector<string> linesVec;
		while (not file.eof()){
            getline(file, line);
			linesVec.push_back(line);
		}
		vector<string> tokens;
		parameters param;
		getInfoFirstLine(linesVec[0], param);
		products product;
		param.nbProductTypes = stoi(linesVec[1]);
		getInfoProductsWeigh(linesVec[2], param);
		param.nbWarehouses = stoi(linesVec[3]);
		vector <warehouses> vectWh;
		//~ warehouses wareh;
		int pos(param.nbWarehouses);
		int posi(4);
		while (posi < 4+pos*2){
			warehouses wareh;
			getLocationW(linesVec[posi], wareh);
			getProductsW(linesVec[posi+1], wareh, param);
			vectWh.push_back(wareh);
			posi+=2;
		}
		posi -= 2; 
		vector <orders> vectOrd;
		while(posi < linesVec.size()-3){
			orders ord;
			getLocationO(linesVec[posi], ord);
			getProductNumber(linesVec[posi+2], ord, param);
			vectOrd.push_back(ord);
			posi+=3;
		}
	}
	return 0;
}
