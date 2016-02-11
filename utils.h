using namespace std;

struct parameters{
    int rows;
    int columns;
    int drones;
    int turns;
    int maxPayload;
    int nbWarehouses;
    int nbProductTypes;
    vector<int> productTypesWeight;
};

struct place{
    uint x;
    uint y;
};

struct products{
	int type;
	int weight;
	int number;
};

struct warehouses{
	place location;
	vector<products> productsStored;
};

struct orders{
	place location;
	vector<products> productsList;
};


void getProductNumber(const string& line, orders& oneOrder, const parameters& param);
//~ void getProductsO(const string& line, orders& ord, const parameters& param);

void split(const string& s, char delim,vector<string>& v);
void getInfoFirstLine(const string& line0,  parameters& param);
void getInfoProductsWeigh(const string& line, parameters& param);
void getLocationW(const string& line, warehouses& wareh);
void getLocationO(const string& line, orders& order);
void getProductsW(const string& line, warehouses& wareh, const parameters& param);
