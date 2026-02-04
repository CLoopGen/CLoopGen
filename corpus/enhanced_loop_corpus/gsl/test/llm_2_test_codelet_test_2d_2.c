#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Access every second element in a strided manner, then complete the rest in a second pass
    size_t stride = 2;
    size_t offset;
    for (offset = 0; offset < stride; offset++) {
        for (i = offset; i < N * tda; i += stride) {
            data[i] = 12345. + i;
        }
    }
}
