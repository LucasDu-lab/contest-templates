#include <iostream>
#include <cmath>
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
int inv(int a,int mod,int c=1){
    int x0,y0;
    int d=exgcd(a,mod,x0,y0);
    int x1=x0*c/d,y1=y0*c/d,dx=mod/d,dy=a/d;
    int smin=ceil((-x1+1.00)/dx),smax=floor((y1-1.00)/dy);
    return x1+smin*dx;
}