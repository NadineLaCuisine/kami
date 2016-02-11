#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//~ void parseLine(string line){
//~ vector<string> parseLine(string line){
	//~ string delimiter(" ");
	//~ string token;
	//~ uint pos(0);
	//~ while ((pos = line.find(delimiter)) != string::npos) {
    //~ token = line.substr(0, pos);
    //~ cout << token << endl;
    //~ line.erase(0, pos + delimiter.length());
	//~ }
//~ }


//~ vector<string> split(const string &line, char delim) {
    //~ vector<string> elems;
    
    //~ return split(line, delim);
//~ }

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

//~ vector<string> split(const string &s, char delim) {
    //~ stringstream ss(s);
    //~ string item;
    //~ vector<string> tokens;
    //~ while (getline(ss, item, delim)) {
        //~ tokens.push_back(item);
    //~ }
    //~ return tokens;
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
		//~ split(tokens, linesVec[0], " ");
		//~ split(linesVec[0], ' ')
		//~ vector<string> firstLine;
		//~ firstLine = split(linesVec[0], ' ');

		split(linesVec[0], ' ', tokens);
		for (uint i(0); i < tokens.size(); ++i){
			cout << tokens[i] << endl;
		}
	}
	return 0;
}
