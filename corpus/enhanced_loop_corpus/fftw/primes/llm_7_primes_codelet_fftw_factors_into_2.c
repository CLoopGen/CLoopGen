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
    INT local_n = n;
    for (; primes[i] != 0; ++i) {
        for (; (local_n % primes[i]) == 0 && local_n > 1; ) {
            local_n /= primes[i];
        }
    }
    n = local_n;
}
