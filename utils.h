using namespace std;

struct parameters{
    string rows;
    string columns;
    string drones;
    string turns;
    string maxPayload;
    string nbWarehouses;
    string nbProductTypes;
    vector<int> productTypesWeight;
};

struct place{
    uint x;
    uint y;
};

struct products{
	int type;
	int weight;
};

struct warehouses{
	place location;
	vector<products> productsStored;
};

struct orders{
	place location;
	//~ uint nbItems;
	vector<products> productsList;
};

void split(const string& s, char delim,vector<string>& v);
void getInfoFirstLine(const string& line0,  parameters& param);
void getInfoProductsWeigh(const string& line, parameters& param);
void getLocationW(const string& line, warehouses& wareh);
void getLocationO(const string& line, orders& order);
void getProductsW(const string& line, warehouses& wareh, const parameters& param);
