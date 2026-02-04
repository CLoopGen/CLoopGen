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
    for (i = 0; i < N * 2; i++) {
        size_t idx = i / 2;
        dest[idx] = src[idx] + 0.1 * src[idx] - 0.05 * src[idx];
    }
}
