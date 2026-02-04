#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern  INT *primes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT i = 0;
    for (; primes[i] != 0; ++i) {
        for (; (n % primes[i]) == 0 && n > 1; ) {
            n /= primes[i];
        }
    }
}
