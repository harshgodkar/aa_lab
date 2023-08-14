#include <bits/stdc++.h>
using namespace std;
// #define ull unsigned long long

int power(int a, int x, int n){
    int res = 1;
    while( x > 0){
        if(x % 2 == 1){
            res = (res * a) % n;
        }
        x /= 2;
        a = (a * a) % n;
    }
    return res;
}



int main() {
    cout <<"Enter a number : \n";
    int n; cin >> n;
    
    int count = 0;
    
    for(int a = 2; a <= n-2; a++){
        int t = power(a, n-1, n);
        if(t == 1)
            count++;
    }
    
    cout << "Count : " << count << endl;
    
    cout << "Probabilty : " << ((float) count / (n-3)) * 100 << "%" << endl;

    return 0;
}

