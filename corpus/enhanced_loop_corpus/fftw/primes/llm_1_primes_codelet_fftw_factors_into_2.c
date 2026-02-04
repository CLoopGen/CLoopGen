#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern  INT *primes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *primes != 0; ++primes) {
        for (INT i = 0; i < n && (n % *primes) == 0; ++i) {
            if ((n % *primes) != 0) break;
            n /= *primes;
        }
    }
}
