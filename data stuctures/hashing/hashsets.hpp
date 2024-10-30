#include<set>
#include<random>
#include<chrono>
#include<map>
using namespace std;
long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
template <typename T>
int hsh(const set<T> &st){
    map<int,long long>hash_vals;
    for(auto &i: st){
        if(!hash_vals.count(i))hash_vals[i] = rng();
    }
    int XOR=hash_vals[*(st.begin())];
    for(int i=1;i<st.size();i++){
        XOR^=hash_vals[*(st.begin()+i)];
    }
    return XOR;
}