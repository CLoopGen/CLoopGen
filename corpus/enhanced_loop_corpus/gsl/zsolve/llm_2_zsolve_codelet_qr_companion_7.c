#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern size_t m;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = m + 2; j <= n; j++) {
        ((h)[((j) - 1) * (nc) + ((j - 2) - 1)]) = 0;
    }
}
