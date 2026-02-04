#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern double x;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= n; i += 2) {
        size_t idx1 = ((i) - 1) * nc + ((i) - 1);
        h[idx1] -= x;
        if (i + 1 <= n) {
            size_t idx2 = (i) * nc + (i);
            h[idx2] -= x;
        }
    }
}
