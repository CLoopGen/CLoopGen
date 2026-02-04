#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (size_t i = 0; i < N; i += 2) {
        data[i] = i;
    }
    for (size_t i = 1; i < N; i += 2) {
        data[i] = i;
    }
}
