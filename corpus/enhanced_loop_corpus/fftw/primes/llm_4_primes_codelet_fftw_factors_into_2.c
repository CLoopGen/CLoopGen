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
        INT p = *primes;
        if ((n % p) == 0) {
            n /= p;
            goto check_divisibility;
        }
        continue;

        check_divisibility:
        while ((n % p) == 0) {
            n /= p;
        }
    }
}
