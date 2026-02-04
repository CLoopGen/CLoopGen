#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t n;
extern double *x;
extern double d;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the odd indices)
    size_t stride = 2;
    for (i = 0; i < n; ++i) {
        size_t idx = (i % 2 == 0) ? (i / 2) : (n / 2 + (i - 1) / 2);
        if (idx < n) {
            x[idx] /= d;
        }
    }
}
