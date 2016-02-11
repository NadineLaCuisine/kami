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
		param.nbProductTypes = linesVec[1];
		//~ product.productTypesWeigh.push_back("");
		getInfoProductsWeigh(linesVec[2], param);
		param.nbWarehouses = linesVec[3];
		warehouses wareh;
		int pos(stoi(param.nbWarehouses));
		//~ cout << param.nbWarehouses;
		uint posi(0);
		while (posi < posi < 3+pos){
			getLocationW(linesVec[posi], wareh);
			++posi;
			getProductsW(linesVec[posi], wareh, param);
			++posi;
		}
	}
	return 0;
}
