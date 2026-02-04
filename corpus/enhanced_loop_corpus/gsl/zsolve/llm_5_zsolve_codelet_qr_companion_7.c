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
    for (i = m + 2; i <= n; i++) {
        if (i % 2 == 0) {
            ((h)[((i) - 1) * (nc) + ((i - 2) - 1)]) = 0;
        }
    }
}
