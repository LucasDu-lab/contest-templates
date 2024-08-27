#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Matrix{
    vector<vector<T> >mat;
    int rows, cols;
    Matrix(int r,int c){
        rows = r;
        cols = c;
        mat.resize(r,vector<T>(c));
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