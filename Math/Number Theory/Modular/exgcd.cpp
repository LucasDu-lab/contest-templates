#include<iostream>
#include<numeric>
#include<tuple>
#include<cassert>
#include<cmath>
using namespace std;
#define int long long
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int a,b,c,x0,y0;
        cin>>a>>b>>c;
        int d=exgcd(a,b,x0,y0);
        if(c%d!=0){
            cout<<-1<<endl;//no solution
            continue;
        }
        //int x0,y0;
        //exgcd(a,b,x0,y0);
        int x1=x0*c/d,y1=y0*c/d,dx=b/d,dy=a/d;
        assert(dy*d==a&&dx*d==b);
        assert(y1*d==y0*c);
        assert(x1*d==x0*c);
        int smin=ceil((-x1+1.00)/dx),smax=floor((y1-1.00)/dy);
        if(smax<smin){
            cout<<x1+smin*dx<<" "<<y1-smax*dy<<"\n";//min positive values of x and y if there are no solutions where x and y are positive integers
            continue;
        }
        cout<<smax-smin+1<<" "<<x1+smin*dx<<" "<<y1-smax*dy<<" "<<x1+smax*dx<<" "<<y1-smin*dy<<"\n";
        //       ^                   ^              ^                 ^                 ^                      
        //  number of solutions    minimum x       minimum y         maximum x         maximum y                 
    }
    cout<<flush;
    return 0;
}