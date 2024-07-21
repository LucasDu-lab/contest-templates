#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
/*For better performance
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}
*/
//shorter version of isPrime function
bool isprime(int n){
    if(n<2)return false;
    for(int j=2;j*j<=n;j++){
      if(n%j==0)return false;
    }
    return true;
}