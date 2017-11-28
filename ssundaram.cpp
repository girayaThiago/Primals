// C++ program to prunsigned long long int primes smaller than n using
// Sieve of Sundaram.
// #include <bits/stdc++.h>
#include "/Users/thiagodantas/stdc++.h"
using namespace std;

// Prunsigned long long ints all prime numbers smaller
void SieveOfSundaram(unsigned long long int n)
{
    // In general Sieve of Sundaram, produces primes smaller
    // than (2*x + 2) for a number given number x.
    // Since we want primes smaller than n, we reduce n to half
    unsigned long long int nNew = (n-2)/2;

    // This array is used to separate numbers of the form i+j+2ij
    // from others where  1 <= i <= j
    bool marked[nNew + 1];

    // Initalize all elements as not marked
    memset(marked, false, sizeof(marked));

    // Main logic of Sundaram.  Mark all numbers of the
    // form i + j + 2ij as true where 1 <= i <= j
    for (unsigned long long int i=1; i<=nNew; i++)
        for (unsigned long long int j=i; (i + j + 2*i*j) <= nNew; j++)
            marked[i + j + 2*i*j] = true;

    // Since 2 is a prime number
    if (n > 2)
        cout << 2 << " ";

    // Prunsigned long long int other primes. Remaining primes are of the form
    // 2*i + 1 such that marked[i] is false.
    for (unsigned long long int i=1; i<=nNew; i++)
        if (marked[i] == false)
            cout << 2*i + 1 << " ";
}

// Driver program to test above
int main(void)
{
    unsigned long long int n = 100;
    SieveOfSundaram(n);
    return 0;
}
