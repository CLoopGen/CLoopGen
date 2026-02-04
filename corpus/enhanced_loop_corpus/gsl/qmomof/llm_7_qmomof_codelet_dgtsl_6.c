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
    for (k = n; k > 4; k -= 2) {
        size_t kb1 = k - 3;
        size_t kb2 = k - 4;

        double val1 = (b[kb1] - d[kb1] * b[kb1 + 1] - e[kb1] * b[kb1 + 2]) / c[kb1];
        b[kb1] = val1;

        if (kb2 > 0) {
            double val2 = (b[kb2] - d[kb2] * b[kb2 + 1] - e[kb2] * b[kb2 + 2]) / c[kb2];
            b[kb2] = val2;
        }
    }

    // Handle any remaining element when step size skips
    if (k == 4) {
        size_t kb = 1;
        b[kb] = (b[kb] - d[kb] * b[kb + 1] - e[kb] * b[kb + 2]) / c[kb];
    }
}
