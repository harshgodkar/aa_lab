#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int gcd(ull a, ull b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int power(ull a, ull x, ull n){
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

bool isPrime(ull n){
    if(n <= 1 || n==4)
        return false;
    if(n <= 3)
        return true;
        
    int k = 200;
    while(k > 0){
        srand(0);
        ull a = 2 + rand() % (n-3) ;
        
        if(gcd(n, a) != 1){
            return false;
        }
        if(power(a, n-1, n) != 1){
            return false;
        }
        k--;
    }
    return true;
}


int main() {
    
    cout <<"Enter a number : \n";
    ull num; cin >> num;
    
    if(isPrime(num)){
        cout << num << " is Prime.\n";
    }
    else{
        cout << num << " is not Prime.\n";
    }

    return 0;
}
