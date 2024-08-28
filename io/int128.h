#include<iostream>
#include<sstream>
using namespace std;
istream& operator>>(istream& in,  __int128 &a){
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
/*
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }
*/