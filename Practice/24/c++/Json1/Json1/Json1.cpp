#include <iostream>
#include<nlohmann/json.hpp>
#include<map>
#include<iomanip>
#include<fstream>

using namespace std;
using json = nlohmann::json;

int main()
{
    int p = 0;
    ifstream in("in.json");
    map <int, int> dict;
    json pjs;
    in >> pjs;
    while (p < pjs.size()) 
    {
        if (pjs[p]["completed"] == true)
        {
            dict[pjs[p]["userId"]] += 1;
        } 
        p++;
    }
    json k = json::array();
    for (auto m : dict){
        k.push_back({ {"userId",m.first}, {"task_completed",m.second }});
    }
    ofstream vjs("out.json");
    vjs << std::setw(3) << k << endl;
    return 0;
}
