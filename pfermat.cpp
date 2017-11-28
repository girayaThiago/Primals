// C++ program to find the smallest twin in given range
// #include <bits/stdc++.h>
#include "/Users/thiagodantas/stdc++.h"
using namespace std;

/* Iterative Function to calculate (a^n)%p in O(logy) */
unsigned long long int power(unsigned long long int a, unsigned long long int n, unsigned long long int p)
{
    unsigned long long int res = 1;      // Initialize result
    a = a % p;  // Update 'a' if 'a' >= p

    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res*a) % p;

        // n must be even now
        n = n>>1; // n = n/2
        a = (a*a) % p;
    }
    return res;
}

// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
bool isPrime(unsigned long long int n, unsigned long long int k)
{
   // Corner cases
   if (n <= 1 || n == 4)  return false;
   if (n <= 3) return true;

   // Try k times
   while (k>0)
   {
       // Pick a random number in [2..n-2]
       // Above corner cases make sure that n > 4
       unsigned long long int a = 2 + rand()%(n-4);

       // Fermat's little theorem
       if (power(a, n-1, n) != 1)
          return false;

       k--;
    }

    return true;
}

// Driver Program to test above function
int main()
{
    for (unsigned long long int i=0; i<1000; i++)
        if (isPrime(i, 10)) cout << i << endl;
    return 0;
}
