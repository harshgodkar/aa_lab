#include <bits/stdc++.h>
using namespace std;

void string_matcher(string text, string pattern, vector<int> pi){
    int n = text.length();
    int m = pattern.length();
    int q = 0;
    for(int i = 0; i < n; i++){
        while(q > 0 && pattern[q] != text[i]){
            q = pi[q-1];
        }
        if(pattern[q] == text[i]){
            q++;
        }
        if(q == m){
            cout << "String occurs with shift " << (i - m + 1) << endl;
            q= pi[q-1];
        }
    }
    
}

int main(){
    string pattern = "acac";
    string text = "acacacacac";

    
    
    int n = text.length();
    int m = pattern.length();

    int cnt = 0;
    vector<int> pi(m,0);
    int k = 0;
    pi[0] = 0;
    for(int q = 1; q < m; q++) {
        
        while(k > 0 && pattern[k] != pattern[q]) {
            if(k == 0){
                pi[q] = 0;
            }
            k = pi[k-1];
        }
        if(pattern[k] == pattern[q]){
            k++;
        } 
        pi[q] = k;
    }

    cout << "Pie Table : \n";
    for(int i=0; i < pi.size(); i++){
        cout << pi[i] << " ";
    }   
    cout << endl;
    
    string_matcher(text, pattern, pi);
    
    return 0;
}
