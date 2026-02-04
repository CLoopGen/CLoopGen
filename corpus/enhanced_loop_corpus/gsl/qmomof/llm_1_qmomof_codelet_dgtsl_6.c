#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern double *c;
extern double *d;
extern double *e;
extern double *b;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = n; i > 2; i--) {
        for (k = i; k > i - 1; k--) {
            size_t kb = k - 3;
            b[kb] = (b[kb] - d[kb] * b[kb + 1] - e[kb] * b[kb + 2]) / c[kb];
        }
    }
}
