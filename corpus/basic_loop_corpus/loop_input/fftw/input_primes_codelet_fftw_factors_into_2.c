#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

INT n;
INT *primes;

void init_vars() {
    n = 9699690; // product of primes 2 through 19, ensures multiple divisions

    // Allocate memory for primes array: small set of primes to avoid overflow
    primes = (INT*)malloc(10 * sizeof(INT));
    if (!primes) exit(1);

    // Initialize with first few primes, ending with 0 as sentinel
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    primes[3] = 7;
    primes[4] = 11;
    primes[5] = 13;
    primes[6] = 17;
    primes[7] = 19;
    primes[8] = 23;
    primes[9] = 0; // termination condition
}