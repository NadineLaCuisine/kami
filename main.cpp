#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



int main(int argc, char ** argv){
	if (argc < 3){
		cout << "command line" << endl;
	} else {
		string fileName = argv[1];
		uint k = stoi(argv[2]);
		ifstream readStructFile(fileName);
        ofstream out("out.fa");
		//
		//~ for (uint i(0); i<sequencesVec.size(); ++i){
			//~ if (not sequencesVec[i].sequence.empty()){
				//~ out<<sequencesVec[i].sequence << endl;
			//~ }
		//~ }
	}
	return 0;
}
