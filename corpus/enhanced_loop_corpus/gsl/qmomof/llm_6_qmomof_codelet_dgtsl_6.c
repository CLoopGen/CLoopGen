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
    for (k = n; k > 2; k--) {
        size_t kb = k - 3;
        double temp1 = d[kb] * b[kb + 1];
        double temp2 = e[kb] * b[kb + 2];
        b[kb] = (b[kb] - temp1 - temp2) / c[kb];
    }
}
