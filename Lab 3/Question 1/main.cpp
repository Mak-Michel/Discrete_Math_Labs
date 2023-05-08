#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sieve (long long number)
{
    vector<bool> primes(number+1, true);                    // suppose all numbers are primes
    primes[0] = primes[1] = false;                          // 0 , 1 are not primes
    for (long long i = 2 ; i <= number ; i++)
    {
        if (primes[i] && (i * i) <= number)
        {
            for (long long j = i * i ; j <= number ; j += i)    // removing all multiples of a prime
            {
                primes[j] = false;
            }
        }
    }
    for(long long i = 2 ; i <= number ; i++)                    // printing the primes
    {
        if(primes[i])
            cout << i << endl;
    }
}

int main()
{
    long long input;
    cout << "Enter the limit number:";
    cin >> input;
    cout << "The primes are:" << endl;
    sieve(input);
    return 0;
}
