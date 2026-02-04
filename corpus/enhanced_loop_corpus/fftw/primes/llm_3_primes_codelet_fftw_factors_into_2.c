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
    INT stride = 1; // Strided access with step 1 (can be adjusted)
    for (; *(primes + i * stride) != 0; i += stride) {
        INT prime_val = *(primes + i * stride);
        for (; (n % prime_val) == 0 && n != 0; n /= prime_val);
    }
}
