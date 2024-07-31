#include<iostream>
#include<sstream>
using namespace std;
istream& operator<<(istream& in,  __int128 &a){
    string s;
    in >> s;
    __int128 res = 0;
    for(int i = s.size() - 1; i >= (s[0]=='-'?1:0); i--){
        res = res * 10 + (s[i] - '0');
    }
    if(s[0] == '-'){
        res = -res;
        s = s.substr(1);
    }
    return in;
}
ostream& operator<<(ostream& out, __int128 a){
    if(a < 0){
        out << '-';
        a = -a;
    }
    stringstream ss;
    ss << a;
    return out << ss.str();
}