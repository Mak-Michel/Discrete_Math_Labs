#include <bits/stdc++.h>

using namespace std;


// computes a power m (mod n) by modular exponentiation
int Modular_Exponentiation(int a , int m , int n){
    int result = 1;
    int power = a % n;
    while(m){
        if(m & 1)                           //if ai = 1
            result = (result * power) % n;
        power = (power * power) % n;
        m >>= 1;
    }
    return result;
}

// perform the Miller's Rabin Primality test on the given number n and return true if it is prime , false otherwise
bool Miller_Test(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    long long k,m;
    for(k = 1 ; k < log2(n) ; k++){             //finds m, k such that n-1 = m * 2^k
        if((n-1) % (long long)pow(2,k) != 0 ){
            m = (n-1)/pow(2,--k);
            break;
        }
    }
    int T = Modular_Exponentiation(2, m, n);    //find the Test variable which is T = a^m (mod n) where we choose a = 2
    if(T == 1 || T == n-1) return true;         //if T = 1 or T = n-1 then n is probably prime

    for(int i = 0; i < k; i++){
        T = Modular_Exponentiation(T, 2, n);    //T = T^2 (mod n)
        if(T == 1) return false;
        if(T == n-1) return true;
    }
    return false;
}




int main()
{
    cout << "Enter number to be tested for primality"<<endl;
    int n;
    cin >> n;
    if(Miller_Test(n)) cout << n << " is probably a Prime number";
    else cout << n << " is a composite number";
}
