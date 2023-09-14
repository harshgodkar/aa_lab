#include <bits/stdc++.h>
using namespace std;

bool knapsack(vector<int> p, vector<int> w, int c, int v){
    int n = w.size();
    
    int mat[n+1][c+1];
    for(int i=0; i <= c; i++){
        mat[0][i] = 0;
    }
    for(int i=0; i <= n; i++){
        mat[i][0] = 0;
    }
    
    for(int i=1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            if(w[i] <= j){
                mat[i][j] = max(p[i] + mat[i-1][j - w[i]], mat[i-1][j]);
            }
            else{
                mat[i][j] = mat[i-1][j];
            } 
        }
    }
    
    if(mat[n][c] >= v){
        return true;
    }
    else{
        return false;
    }
}

void sos(vector<int> s, int sum){
    vector<int> p = s;
    vector<int> w = s;
    int c = sum;
    int v = sum;
    
    if(knapsack(p, w, c, v)){
        cout << "Sum Of SubSet is Reducible to 0/1 Knapsack" << endl;
    }
    else{
        cout << "Sum Of SubSet is can't Reduce to 0/1 Knapsack" << endl;
    }
}


int main(){
    vector<int> s = {4, 3, 6, 8, 5, 9};
    int sum = 23;
    
    sos(s, sum);
    
    return 0;
}


