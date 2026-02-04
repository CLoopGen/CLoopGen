#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;

INT n0l = 0;
INT n0u;
INT n1l = 0;
INT n1u;
INT s0;
INT s1;
INT vl = 4;
INT i0;
INT i1;
INT v;

R *I;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    INT n0 = 512;
    INT n1 = 512;
    
    n0u = n0;
    n1u = n1;
    
    s0 = n1 * vl;
    s1 = vl;
    
    size_t total_elements = n0 * n1 * vl;
    I = (R*)aligned_alloc(32, total_elements * sizeof(R));
    
    if (!I) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_elements; ++i) {
        I[i] = (R)(i & 511);
    }
}