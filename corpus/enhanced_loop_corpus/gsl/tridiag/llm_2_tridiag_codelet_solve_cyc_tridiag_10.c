#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *alpha;
extern double *c;
extern double *z;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in a strided pattern)
    for (i = 0; i < N; i += 2) {
        c[i] = z[i] / alpha[i];
    }
    // Handle odd-sized N if needed by processing last element
    if (N % 2 == 1) {
        c[N-1] = z[N-1] / alpha[N-1];
    }
}
