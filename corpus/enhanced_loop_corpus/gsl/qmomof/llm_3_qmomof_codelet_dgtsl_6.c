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
for (k = n; k > 2; k -= 2) {
    if (k > 3) {
        size_t kb1 = k - 3;
        b[kb1] = (b[kb1] - d[kb1] * b[kb1 + 1] - e[kb1] * b[kb1 + 2]) / c[kb1];
    }
    if (k > 4) {
        size_t kb2 = k - 4;
        b[kb2] = (b[kb2] - d[kb2] * b[kb2 + 1] - e[kb2] * b[kb2 + 2]) / c[kb2];
    }
}
}
