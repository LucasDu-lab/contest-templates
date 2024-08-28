#include<bits/stdc++.h>
using namespace std;

//template<typename T>
struct Matrix{
    vector<vector<int> >mat;
    int rows, cols;
    Matrix(int r,int c){
        rows = r;
        cols = c;
        mat.resize(r,vector<int>(c));
    }
    Matrix operator=(Matrix B){
        mat.resize(B.rows,vector<int>(B.cols));
        mat = B.mat;
        rows = B.rows;
        cols = B.cols;
        return *this;
    }
    Matrix operator+(Matrix B){
        if(rows!= B.rows || cols!= B.cols) throw runtime_error("Matrices must have the same dimensions for addition");
        Matrix C(rows, cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                C.mat[i][j] = mat[i][j] + B.mat[i][j];
            }
        }
        return C;
    }
    Matrix operator +=(Matrix B){
        return *this = *this + B;
    }
    Matrix operator-(Matrix B){
        if(rows!= B.rows || cols!= B.cols) throw runtime_error("Matrices must have the same dimensions for subtraction");
        Matrix C(rows, cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                C.mat[i][j] = mat[i][j] - B.mat[i][j];
            }
        }
        return C;
    }
    Matrix operator-=(Matrix B){
        return *this = *this - B;
    }
    Matrix operator*(Matrix B){
        if(cols!= B.rows) throw runtime_error("Number of columns in the first matrix must match the number of rows in the second matrix for multiplication");
        Matrix C(rows, B.cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<B.cols; j++){
                for(int k=0; k<cols; k++){
                    C.mat[i][j] += mat[i][k] * B.mat[k][j];
                }
            }
        }
        return C;
    }
    Matrix operator*=(Matrix B){
        return *this = *this * B;
    }
    Matrix operator%(int b){
        Matrix B(rows,cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                B.mat[i][j] = mat[i][j] % b;
            }
        }
    }
    Matrix operator%=(int b){
        return *this = *this % b;
    }
    Matrix transpose(){
        Matrix C(cols, rows);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                C.mat[j][i] = mat[i][j];
            }
        }
        return C;
    }
    
};
Matrix identitymat(int n){
    Matrix mat(n,n);
    for(int i=0;i<n;i++){
        mat.mat[i][i]=1;
    }
    return mat;
}
Matrix pow(Matrix a,int p, int mod=1e9+7){
    if(a.rows!=a.cols)throw runtime_error("Matrix must be square to multiply itself");
    if(p==0) return identitymat(a.rows);
    Matrix half = pow(a, p/2, mod);
    half *= half;
    half %=mod;
    if(p%2==1) half *= a;
    half %= mod;
    return half;
}
ostream& operator<<(ostream& out,Matrix matrix){
    for(auto a : matrix.mat){
        for(auto b : a){
            out<<b<<" ";
        }
        out<<endl;
    }
    return out;
}
istream & operator>> (istream & in, Matrix matrix){
    for(auto &a : matrix.mat){
        for(auto &b : a){
            in>>b;
        }
    }
    return in;
}
int determinant(Matrix A,int p)
{
    int n=A.rows;
    if(A.rows!=A.cols)throw runtime_error("Matrix must be square to calculte determinant");
   int res=1,w=1;
	for(int i=1;i<=n;i++)
	{ 
		for(int j=i+1;j<=n;++j)
		{
    		while(A.mat[i][i])
			{
     	    	int div=A.mat[j][i]/A.mat[i][i];
        		for(int k=i;k<=n;++k)
				{
        		    A.mat[j][k]=((A.mat[j][k]-div*A.mat[i][k])%p+p)%p;
        		}
        		swap(A.mat[i],A.mat[j]);w=-w;
    		}
    		swap(A.mat[i],A.mat[j]);w=-w;
		}
	}
	for(int i=1;i<=n;i++)res=(A.mat[i][i]*res)%p;
	res=w*res;
	return (res+p)%p;
}