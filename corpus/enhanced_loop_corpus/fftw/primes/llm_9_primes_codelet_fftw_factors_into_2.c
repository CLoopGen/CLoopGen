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
    INT prime_val;
    for (; primes[i] != 0; ++i) {
        prime_val = primes[i];
        for (INT j = 0; j < 5 && n > 1; ++j) {
            if ((n % prime_val) == 0) {
                n /= prime_val;
            } else {
                break;
            }
        }
    }
}
