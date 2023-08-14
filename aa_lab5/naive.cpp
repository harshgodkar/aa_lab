#include<bits/stdc++.h>
using namespace std;

void naive_matching(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    for(int s=0; s <= n-m; s++){
        int i = 1, j = 1;
        while(j <= m && text[s+i] == pattern[j]){
            i++;j++;
        }
        if(j == m){
            cout << "Pattern Occurs with Shift : " << s << endl;
        }
    }
}

int main(){
    
    string text = "JIM_SAW_ME_IN_A_BOOK_SHOP";
    string pattern = "BOOK";
    naive_matching(text, pattern);
    
    return 0;
}
