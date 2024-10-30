#include<utility>
#include<unordered_map>
using namespace std;
namespace std{
    template<> struct hash<pair<int,int> >{
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    
}
//use just like a standard type, like unordered_map<pair<int,int>,int>