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
		int posi(4);
		//~ cout << 4+pos << endl;
		//~ cout << linesVec[4] << endl;
		//~ cout << "size" << linesVec.size() << endl;
		while (posi < 4+pos){
			//~ cout << "** " << posi << endl;
			//~ cout << "****" << linesVec[posi];
			getLocationW(linesVec[posi], wareh);
			getProductsW(linesVec[posi+1], wareh, param);
			++posi;
		}
		while(posi < linesVec.size()){
			
			++posi;
		}
	}
	return 0;
}
