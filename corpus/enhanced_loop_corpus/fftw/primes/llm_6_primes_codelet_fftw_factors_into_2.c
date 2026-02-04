#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern  INT *primes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT temp_n = n;
    for (; *primes != 0; ++primes) {
        if ((temp_n % *primes) == 0) {
            temp_n /= *primes;
            --primes; // reintroduce loop-carried dependency via index manipulation
        }
    }
    n = temp_n;
}
