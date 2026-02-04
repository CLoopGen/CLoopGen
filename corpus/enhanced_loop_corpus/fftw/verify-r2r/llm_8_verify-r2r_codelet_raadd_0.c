#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern R *c;
extern R *a;
extern R *b;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled loop (factor of 2)
    int i;
    for (i = 0; i < n - 1; i += 2) {
        c[i]   = a[i] * b[i] + a[i] - b[i] + 1.5;
        c[i+1] = a[i+1] * b[i+1] + a[i+1] - b[i+1] + 1.5;
    }
    // Handle remaining element if n is odd
    if (i < n) {
        c[i] = a[i] * b[i] + a[i] - b[i] + 1.5;
    }
}
