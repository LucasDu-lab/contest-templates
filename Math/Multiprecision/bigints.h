#include <iostream>
#include <cstdio>
#include <numeric>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign{
	int nums[5000];
	int len;
	bign(){len=0;memset(nums,0,sizeof(nums));}
	bool operator >(const bign other){
		if(len>other.len){
			return true;
		}
		for(int i=max(len,other.len)-1;i>=0;i--){
			if(nums[i]!=other.nums[i]){
				return nums[i]>other.nums[i];
			}
		}
		return false;
	}
};
void s2big(string s,bign &b){
	b.len=s.size();
	reverse(s.begin(),s.end());
	for(int i=0;i<b.len;i++){
		b.nums[i]=s[i]-'0';
	}
	assert(b.nums[0]!=0);
}
void printBIG(bign a){
	reverse(a.nums,a.nums+a.len);
	for(int i=0;i<a.len;i++){
		cout<<a.nums[i];
		
	}
	cout<<endl;
}
bign add(bign a,bign b){
	bign res;
	res.len=max(a.len,b.len);
	int carry=0;
	for(int i=0;i<res.len;i++){
		res.nums[i]=a.nums[i]+b.nums[i]+carry;
		carry=res.nums[i]/10;
		res.nums[i]%=10;
	}
	if(carry>0){
		res.len++;
		res.nums[res.len-1]=carry;
	}
	return res;
}
bign minusBIG(bign a,bign b){//there is already a struct named minus
	bign res;
	res.len=max(a.len,b.len);
	for(int i=0;i<res.len;i++){
		if(a.nums[i]<b.nums[i]){
			a.nums[i+1]--;
			a.nums[i]+=10;
		}
		res.nums[i]=a.nums[i]-b.nums[i];
	}
	while(res.nums[res.len-1]==0&&res.len>1){
		res.len--;
	}
	return res;
}
bign mul(bign a,int b){
	bign res;
	res.len=a.len;
	int carry=0;
	for(int i=0;i<res.len;i++){
		res.nums[i]=a.nums[i]*b+carry;
		carry=res.nums[i]/10;
		res.nums[i]%=10;
	}
	while(carry>0){
		res.len++;
		res.nums[res.len-1]=carry%10;
		carry/=10;
	}
	return res;
}
bign divBIG(bign a,int b){// and a function named div
	bign res;
	res.len=a.len;
	int r=0;
	for(int i=a.len;i>=0;i--){
		r=r*10+a.nums[i];
		res.nums[i]=r/b;
		r%=b;
	}
	while(res.nums[res.len-1]==0&&res.len>1)res.len--;
	return res;
}
bign factorial(string a){
	bign b;
	s2big(a,b);
	int e=stoi(a)-1;
	bign res;
	if(e==0||e==-1){
		s2big("1",res);
		return res;
	}
	while(e>1){
		b=mul(b,e);
		e--;
	}
	return b;
}
