using namespace std;


struct parameters{
    string rows;
    string columns;
    string drones;
    string turns;
    string maxPayload;
};

void split(const string& s, char delim,vector<string>& v);
void getInfoFirstLine(const string& line0,  parameters& param);
