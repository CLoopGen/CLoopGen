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
    size_t step;
    for (i = m + 2; i <= n; i++) {
        for (step = 0; step < 3; step++) {
            ((h)[((i) - 1) * (nc) + ((i - 2) - 1) + step]) = step;
        }
    }
}
