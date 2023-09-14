#include<bits/stdc++.h>
using namespace std;

int main(){
    string text = "31415926535269793";
    int n = text.length();
    
    string pattern = "26";
    int m = pattern.length();
    
    int q = 11, d = 10;
    vector<int> t(n-m+1, 0);
    t[0] = 0;
    int p = 0;
    
    int h = ((int)pow(d, m-1)) % q;
    
    //preproccessing
    for(int i=0; i < m; i++){
        p = (d * p + (pattern[i] - '0')) % q;
        t[0] = (d * t[0] + (text[i] - '0')) % q;
    }
    
    //Matching
    for(int s=0; s <= n-m; s++){
        if(p == t[s]){
            if(pattern == text.substr(s, m)){
                cout << "Pattern Occurs with shift : " << s << endl;
            }
        }
        if(s < n-m){
            t[s+1] = (d*(t[s] - (text[s] - '0')*h) + (text[s+m] - '0')) % q;
            if(t[s+1] < 0){
                t[s+1] = t[s+1] + q;
            }
        }
    }
    
}


