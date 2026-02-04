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
    size_t outer;
    size_t inner;
    size_t block_size = 16;
    for (outer = 0; outer < N; outer += block_size) {
        for (inner = outer; inner < ((outer + block_size < N) ? outer + block_size : N); inner++) {
            dest[inner] = src[inner];
        }
    }
}
