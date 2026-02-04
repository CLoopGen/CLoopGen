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
    for (k = n; k > 2 && k <= n; k--) {
        size_t kb = k - 3;
        double denominator = c[kb];
        if (denominator == 0.0) continue;
        double temp = (b[kb] - d[kb] * b[kb + 1] - e[kb] * b[kb + 2]);
        b[kb] = temp / denominator;
    }
}
