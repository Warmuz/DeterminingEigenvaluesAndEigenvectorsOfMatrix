#include <iostream>
using namespace std;
int main() {
    const int n=3;      //Size of matrix
    const int k=8;      //amount of iterratons
    
    double A[n][n]={{1, 3, 2},{2, 1, 2},{1, 2, 1}};     //Matrix in which we determine highest eigenvalue
    double y[n][k];
    double h[n];
    double result=0;
    
    y[0][0]=1;
    for(int i=1 ; i<n ; i++){
        y[i][0]=0;
    }
    
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            y[j][i]=0;
            
            for(int z=0;z<n;z++){
                y[j][i] += A[j][z] * y[z][i-1];
            }
        }
    }
    
    for(int i=0;i<n;i++){
        h[i]=y[i][k]/y[i][k-1];
        result += h[i];
    }
    result /= n;
    cout<<"The highest-modulus eigenvalue: "<<result<<endl;
}
