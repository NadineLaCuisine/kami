#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


void split(const string& s, char delim,vector<string>& v) {
    auto i = 0;
    auto pos = s.find(delim);
    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}

void getInfoFirstLine(const string& line0, parameters& param){
    vector<string> tokens;
    split(line0, ' ', tokens);
    param.rows = stoi(tokens[0]);
    param.columns = stoi(tokens[1]);
    param.drones = stoi(tokens[2]);
    param.turns = stoi(tokens[3]);
    param.maxPayload = stoi(tokens[4]);
}

void getInfoProductsWeigh(const string& line, parameters& param){
    vector<string> tokens;
    split(line, ' ', tokens);
    for (uint i(0); i < tokens.size(); ++i){
        param.productTypesWeight.push_back(stoi(tokens[i]));
    }
    //~ cout << prod.productTypesWeigh[0] << " " <<prod.productTypesWeigh[1] <<  endl;
}


void getLocationW(const string& line, warehouses& wareh){
    vector<string> tokens;
    split(line, ' ', tokens);
    //~ cout << tokens.size();
    wareh.location.x = stoi(tokens[0]);
    wareh.location.y = stoi(tokens[1]);
}

void getProductsW(const string& line, warehouses& wareh, const parameters& param){
    vector<string> tokens;
    split(line, ' ', tokens);
    for (uint i(0); i < tokens.size(); ++i){
        products prod;
        prod.type = i;
        prod.number = stoi(tokens[i]);
        prod.weight = param.productTypesWeight[i];
        wareh.productsStored.push_back(prod);
    }
}

void getProductNumber(const string& line, orders& oneOrder, const parameters& param){
	vector<string> tokens;
	split(line, ' ', tokens);
	//~ oneOrder.productsList(param.nbProductTypes);
	for (uint oneProduct=0; oneProduct<param.nbProductTypes; oneProduct++){
		oneOrder.productsList[oneProduct].type = oneProduct;
		oneOrder.productsList[oneProduct].weight = param.productTypesWeight[oneProduct];
		oneOrder.productsList[oneProduct].number = 0;
	}
	//Pour chaque élément
	for (uint i(0); i<tokens.size(); ++i){

		//on lis le type
		int productId = stoi(tokens[i]);

		//On remplie le struct correspondant
		oneOrder.productsList[productId].number++;
	}
}

void getLocationO(const string& line, orders& order){
    vector<string> tokens;
    split(line, ' ', tokens);
    //~ cout << tokens.size() << endl;
    order.location.x = stoi(tokens[0]);
    order.location.y = stoi(tokens[1]);
}


//~ void getProductsO(const string& line, orders& ord, const parameters& param){
    //~ vector<string> tokens;
    //~ split(line, ' ', tokens);
    //~ for (uint i(0); i < tokens.size(); ++i){
        //~ products prod;
        //~ prod.type = i;
        //~ prod.weight = param.productTypesWeight[i];
    //~ }
//~ }
