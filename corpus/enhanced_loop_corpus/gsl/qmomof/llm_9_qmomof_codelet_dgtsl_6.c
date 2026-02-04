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
    size_t kb = k - 3;
    double temp1 = (b[kb] - d[kb] * b[kb + 1] - e[kb] * b[kb + 2]) / c[kb];
    b[kb] = temp1;
    if (k > 3) {
        size_t kb2 = kb - 1;
        b[kb2] = (b[kb2] - d[kb2] * b[kb2 + 1] - e[kb2] * b[kb2 + 2]) / c[kb2];
    }
}
}
