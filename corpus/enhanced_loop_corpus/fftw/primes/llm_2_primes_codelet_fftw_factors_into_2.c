#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern  INT *primes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT *p = primes;
    for (; *p != 0; ++p) {
        INT prime_val = *p;
        for (; (n % prime_val) == 0 && n != 0; n /= prime_val);
    }
}
