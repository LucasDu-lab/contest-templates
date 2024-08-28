#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a[110][110],res[110],eps=1e-8;
int n;
bool Gauss(){
    int flag=1;
    for(int i=1;i<=n;i++){//iterate through all equations
        int p=i;
        for(int j=i+1;j<=n;j++){
            if(abs(a[p][i]<eps)||(abs(a[j][i])>=eps&&abs(a[j][i])<abs(a[p][i]))){
                p=j;//get the easiest to solve
            }
        }
        if(abs(a[p][i])<=eps){flag++;continue;}
        if(i!=p){
            for(int j=1;j<=n;j++){
                swap(a[p][j],a[i][j]);
            }
            swap(res[p],res[i]);
        }
        res[i]/=a[i][i];
        for(int j=i+1;j<=n;j++){
            a[i][j]/=a[i][i];//eliminate
        }
        a[i][i]=1;
        for(int j=1;j<=n;j++){
            if(i!=j){
                res[j]-=res[i]*a[j][i];
                for(int k=i+1;k<=n;k++){
                    a[j][k]-=a[i][k]*a[j][i];
                }
            }
        }
    }
    return flag!=n;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        cin>>res[i];
    }
    cout<<fixed<<setprecision(2);
    if(Gauss()){
        for(int i=1;i<=n;i++){
            cout<<res[i]<<endl;
        }
    }
    else{
        cout<<"No Solution"<<endl;
    }
    return 0;
}