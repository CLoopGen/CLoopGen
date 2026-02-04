#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dest;
extern double *src;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        dest[0] = src[0];
        for (i = 1; i < N; i++) {
            dest[i] = src[i] + dest[i-1] - dest[i-1]; // Introduces WAW and RAW dependencies, but preserves value
        }
    }
}
