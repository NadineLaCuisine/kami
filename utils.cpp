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
    param.rows = tokens[0];
    param.columns = tokens[1];
    param.drones = tokens[2];
    param.turns = tokens[3];
    param.maxPayload = tokens[4];
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
    wareh.location.x = stoi(tokens[0]);
    wareh.location.y = stoi(tokens[1]);
}

void getProductsW(const string& line, warehouses& wareh, const parameters& param){
    vector<string> tokens;
    split(line, ' ', tokens);
    for (uint i(0); i < tokens.size(); ++i){
        products prod;
        prod.type = i;
        prod.weight = param.productTypesWeight[i];
        wareh.productsStored[i] = prod;
    }
}


void getLocationO(const string& line, orders& order){
    vector<string> tokens;
    split(line, ' ', tokens);
    order.location.x = stoi(tokens[0]);
    order.location.y = stoi(tokens[1]);
}
