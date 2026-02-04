#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *A;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (i = (n % 2 == 0 ? n - 2 : n - 1); i >= 0; i -= 2) {
        ((A[i])[1]) = 0.;
    }
    // Handle remaining element if n is odd
    if (n % 2 == 1) {
        ((A[0])[1]) = 0.;
    }
}
