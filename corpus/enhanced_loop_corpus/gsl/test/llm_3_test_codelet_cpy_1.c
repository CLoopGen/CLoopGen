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
    size_t stride = 4;
    for (i = 0; i < N; i++) {
        size_t index = (i * stride) % N;
        dest[index] = src[index];
    }
}
