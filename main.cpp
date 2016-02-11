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
		product.nbProductTypes = linesVec[1];
		//~ product.productTypesWeigh.push_back("");
		getInfoProductsWeigh(linesVec[2], product);
	}
	return 0;
}
