#include<cassert>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include <vector>
#include <numeric>
#include <cstring>
using namespace std;
//requires definition of MOD
const int MOD=1e9+7;
const int RT=5;
struct modint{
    long long v,mod=MOD;
    modint(){v=0;};
    modint(long long _v){v=_v%mod;};
    modint(int _v){v=_v%mod;};
    explicit operator int() const{return v;}
    static constexpr int rt() { return RT; }//primitive root for FFT
    modint operator =(const modint b){
        v=b.v;
        return *this;
    }
    modint operator =(const int b){
        v=b%mod;
        return *this;
    }
    modint operator +(const modint b){
        v%=mod;
        return (v+b.v%mod)%mod;
    }
    modint operator +=(const modint b){
        modint t=*this+b;
        v=t.v;
        return t;
    }
    modint operator -(const modint b){
        return (v-b.v+mod)%mod;
    }
    modint operator -=(const modint b){
        modint t=*this-b;
        v=t.v;
        return *this;
    }
    modint operator *(const modint b){
        long long t=(v*b.v);
        t%=mod;
        int u=t;
        return u;
    }
    modint operator *=(const modint b){
        modint t=(*this)*b;
        v=t.v;
        return (*this);
    }
    friend modint pow(modint a,long long b){
        long long res = 1;
        while (b > 0) {
            if (b&1) { res = res * a.v % MOD; }
            a = (a * a).v % MOD;
            b /= 2;
        }
        return res;
    }
    modint inv(modint a){
        return pow(a,MOD-2);//only prime moduli works
    }
    long long inv(long long x) {
    if(x<=1)return x;
    return MOD-(MOD/x*inv(MOD%x))%MOD;
}
    modint operator/(const modint b){
        return modint(v)*inv(b);
    }

    bool operator <(const modint b){
        return v<b.v;
    }
    bool operator <=(const modint b){
        return v<=b.v;
    }
    bool operator >(const modint b){
        return v>b.v;
    }
    bool operator >=(const modint b){
        return v>=b.v;
    }
    bool operator ==(const modint b){
        return v==b.v;
    }
    bool operator !=(const modint b){
        return v!=b.v;
    }
    modint operator++(int) {
        *this += 1;
        return *this; // for prefix increment
    }

    modint& operator++() {
        *this += 1;
        return *this;
    }
    modint operator--(int) {
        *this -= 1;
        return *this; // for prefix decrement
    }
    modint operator -(){
        return -v;
    }
    modint& operator--() {
        *this -= 1;
        return *this;
    }
    /*long long log(modint b) {
        if (b.v == 1) return 0;
        long long res = 0, m = sqrt(MOD) + 1;
        modint invb = inv(b);
        modint t = pow(*this,m);
        vector<modint> vals(m + 1);
        vals[1] = *this;
        for (int i = 2; i <= m; ++i) {
            vals[i] = vals[i - 1] * invb;
        }
        modint cur = t;
        for (int i = 1; i <= m; ++i) {
            res = (res + m * cur.v) % MOD;
            if (vals[cur.v] == b) {
                return res + i;
            }
            cur = cur * t;
        }
        return -1; // b is not a power of *this
    } modular logarithm - has not been tested before, issues are welcome!*/
};
ostream& operator <<(ostream &out,modint a){
    out<<a.v;
    return out;
}
istream& operator >>(istream &in,modint &a){
    in>>a.v;
    return in;
}

