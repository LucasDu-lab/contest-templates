#include <iostream>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign{
	vector<int>nums;
	int len;
	bign(){len=0;nums.resize(10000);}
    bign(string s){
        len=s.size();
        nums.resize(10000,0);
        reverse(s.begin(),s.end());
        for(int i=0;i<len;i++){
            nums[i]=s[i]-'0';
        }
    }
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
    bool operator <(const bign other){
		if(len<other.len){
			return true;
		}
		for(int i=max(len,other.len)-1;i>=0;i--){
			if(nums[i]!=other.nums[i]){
				return nums[i]<other.nums[i];
			}
		}
		return false;
	}
    bool operator ==(const bign other){
        return nums==other.nums&&len==other.len;
    }
    bool operator<=(const bign other){
        return *this<other||*this==other;
    }
    bool operator>=(const bign other){
        return *this>other||*this==other;
    }
    bool operator!=(const bign other){
        return !(*this==other);
    }
    bign operator +(const bign other){
        bign res;
        res.len=max(len,other.len);
        int carry=0;
        for(int i=0;i<res.len;i++){
            res.nums[i]=nums[i]+other.nums[i]+carry;
            carry=res.nums[i]/10;
            res.nums[i]%=10;
        }
        if(carry>0){
            res.len++;
            res.nums[res.len-1]=carry;
        }
        return res;
    }
    bign operator =(const bign other){
        nums=other.nums;
        len=other.len;
        return *this;
    }
    bign operator +=(const bign other){
        bign t=*this+other;
        nums=t.nums;
        len=t.len;
        return t;
    }
    bign operator -(const bign b){
        bign res;
        res.len=max(len,b.len);
        for(int i=0;i<res.len;i++){
            if(nums[i]<b.nums[i]){
                nums[i+1]--;
                nums[i]+=10;
            }
            res.nums[i]=nums[i]-b.nums[i];
        }
        while(res.nums[res.len-1]==0&&res.len>1){
            res.len--;
        }
        return res;
    }
    bign operator -=(const bign b){
        bign t=*this-b;
        nums=t.nums;
        len=t.len;
        return t;
    }
    bign operator *(const bign b) {
      bign c;  
      c.len=b.len;  
      for (int i = 0; i <b.len+len; ++i) {
        for (int j = 0; j <= i; ++j) c.nums[i] += nums[j] * b.nums[i - j];
    
        if (c.nums[i] >= 10) {
          c.nums[i + 1] += c.nums[i] / 10;
          c.nums[i] %= 10;
          c.len++;
        }
      }
      while(c.nums[c.len-1]==0&&c.len>1){
          //c.nums.pop_back();
          c.len--;
      }
      return c;
    }
    bign operator *=(const bign b){
        bign t=(*this)*b;
        nums=t.nums;
        len=t.len;
        return t;
    }
    bign operator++(int) {
        bign temp("1");
        *this += temp;
        return *this; // for prefix increment
    }

    bign& operator++() {
        *this += bign("1");
        return *this;
    }
    bign operator--(int) {
        bign temp("1");
        *this -= temp;
        return *this; // for prefix decrement
    }

    bign& operator--() {
        *this -= bign("1");
        return *this;
    }
};
ostream& operator << (ostream &out,bign a){
	reverse(a.nums.begin(),a.nums.begin()+a.len);
	for(int i=0;i<a.len;i++){
		out<<a.nums[i];	
	}
	return out;
}
istream& operator >> (istream &in,bign &a){
    string t;
    cin>>t;
    bign b(t);
    a=b;
    return in;
}
void s2big(string s,bign &b){
	b.len=s.size();
	reverse(s.begin(),s.end());
	for(int i=0;i<b.len;i++){
		b.nums[i]=s[i]-'0';
	}
}
void printBIG(bign a){
	reverse(a.nums.begin(),a.nums.begin()+a.len);
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