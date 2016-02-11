#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

//~ void split(const string& s, char delim,vector<string>& v) {
    //~ auto i = 0;
    //~ auto pos = s.find(delim);
    //~ while (pos != string::npos) {
      //~ v.push_back(s.substr(i, pos-i));
      //~ i = ++pos;
      //~ pos = s.find(delim, pos);

      //~ if (pos == string::npos)
         //~ v.push_back(s.substr(i, s.length()));
    //~ }
//~ }


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
		cout << linesVec[0] << endl;
		vector<string> tokens;

		split(linesVec[0], ' ', tokens);
		for (uint i(0); i < tokens.size(); ++i){
			cout << tokens[i] << endl;
		}
	}
	return 0;
}
