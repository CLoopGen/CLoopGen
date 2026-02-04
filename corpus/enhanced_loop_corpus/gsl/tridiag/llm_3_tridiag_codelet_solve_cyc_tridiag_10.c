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
    // Variant 2: Reverse consecutive memory access (process array from end to beginning)
    for (i = N; i-- > 0; ) {
        c[i] = z[i] / alpha[i];
    }
}
