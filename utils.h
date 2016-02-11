using namespace std;

struct parameters{
    string rows;
    string columns;
    string drones;
    string turns;
    string maxPayload;
};

struct products{
	string nbProductTypes;
	vector<string> productTypesWeigh;
};

void split(const string& s, char delim,vector<string>& v);
void getInfoFirstLine(const string& line0,  parameters& param);
void getInfoProductsWeigh(const string& line, products& prod);
