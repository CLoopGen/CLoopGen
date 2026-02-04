#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
INT n = 4096;
INT s0;
INT s1;
INT i0;
INT i1;

void init_vars() {
    s0 = 8192;
    s1 = 1;
    
    size_t total_size = (size_t)s0 * n * sizeof(R);
    I = aligned_alloc(32, total_size);
    
    if (!I) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_size / sizeof(R); ++i) {
        I[i] = sin(i * 0.01) + cos(i * 0.07);
    }
}