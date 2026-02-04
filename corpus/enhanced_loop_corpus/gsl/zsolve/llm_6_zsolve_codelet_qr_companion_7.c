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
    for (i = m + 2; i <= n; i++) {
        j = i - 1;
        ((h)[j * (nc) + (j - 1)]) = 0;
        if (j > m + 1) {
            ((h)[(j-1) * (nc) + (j - 1)]) += ((h)[j * nc + (j - 2)]);
        }
    }
}
