#include <bits/stdc++.h>

using namespace std;

//Perform Sieve Algorithm on the given number and return a vector of integers
//which contains all the Primes less than the passed number
vector<int> Sieve (long long number)
{
    vector<bool> primes(number+1, true);                    // suppose all numbers are primes
    for (long long i = 2 ; i <= sqrt(number) ; i++)
        if (primes[i])
            for (long long j = i * i ; j <= number ; j += i) primes[j] = false; // removing all multiples of a prime

    vector<int> PrimeNumbers;       //the vector which will contain all the prime numbers up to a given limit
    for(long long i = 2 ; i <= number ; i++)    //inserting the primes in the vector
        if(primes[i]) PrimeNumbers.push_back(i);

    return PrimeNumbers;
}


void Prime_Factorization (long long number)
{
    vector<int> PrimeNumbers = Sieve(floor(sqrt(number)));  //finding all the primes less than squareRoot the number
    for(int i = 0; i < PrimeNumbers.size(); i++){
        if(number % PrimeNumbers[i] == 0){                  //if the number is divisible by a prime then print it
            cout << PrimeNumbers[i] << " ";                 //and find the Prime_Factorization of number/prime
            Prime_Factorization(number/PrimeNumbers[i]);
            return;
        }
    }                          //if the number is not divisible by any prime less than sqrt(number)
    cout << number;            //then the number is already prime so print it
}

int main()
{
    long long number;
    cout << "Enter the desired number to be factorized:" << endl;
    cin >> number;
    cout << "The factorization is:" << endl;
    Prime_Factorization(number);
    return 0;
}
