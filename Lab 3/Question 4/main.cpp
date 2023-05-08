#include <bits/stdc++.h>

using namespace std;

int s,t;    //Bezout's Coefficients


//returns the greatest common divisor of two numbers and sets their Bezout's identity recursively
int Gcd(int a,int b){
    if(b == 0){
        s = 1;
        t = 0;
        return a;
    }
    int gcd =  Gcd(b,a % b);
    int temp = s;
    s = t;
    t = temp - t * (a/b);
    return gcd;
}

// finds the inverse of a (mod m) where the inverse is the s bezout's identity
int Inverse(int a, int m){
    Gcd(a,m);
    return s;
}

// it takes vector a as parameter which contains a1,a2,a3, ······ an
// it takes vector M as parameter which contains M in index 0 and M1,M2,M3, ······· Mn
// vector y contains y1,y2,y3, ······ yn. where each individual y is the inverse of the corresponding M (mod m)
// vector m contains m1,m2,m3, ······ mn
// n is the number of equations of linear congruences
int Chinese_Remainder_Theorem(vector<int> a , vector<int> M , vector<int> y , vector<int> m , int n ){
    int X = 0;
    for(int i=1;i<=n;i++){
        y[i] = Inverse(M[i],m[i]);      //Calling the Inverse Function To compute yi
        X += a[i] * M[i] * y[i];        //X is the Summation of a1·M1·y1 + a2·M2·y2 ..... an·Mn·yn
    }
    return X < 0 ? X%M[0] + M[0] : X%M[0];
}



int main()
{
    cout << "Enter number of equations" << endl;
    int n;
    cin >> n;               //number of equations
    vector<int> a(n+1);
    vector<int> m(n+1);
    vector<int> M(n+1);
    vector<int> y(n+1);
    M[0] = 1;       //M[0] will hold the the product of m1· m2· m3 ····· mn
    for(int i=1;i<=n;i++){
        cout << "Enter a" << i << " followed by m" <<i <<endl;
        cin >> a[i] >> m[i];                                        //taking the equations from the user
        M[0] *= m[i];
    }

    for(int i=1;i<=n;i++)               //Computing M1, M2, M3 .... Mn
        M[i] = M[0]/m[i];

    int X = Chinese_Remainder_Theorem(a ,M ,y ,m ,n );              //Calling The Chinese_Remainder_Theorem function to compute X
    cout << "X = " << X << " (mod " << M[0] << ")" << endl;         //printing X
}
