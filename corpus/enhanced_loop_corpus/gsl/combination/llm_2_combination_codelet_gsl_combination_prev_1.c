#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then offset)
    size_t stride = 2;
    for (size_t j = 0; j < stride; j++) {
        for (size_t i = j; i < k; i += stride) {
            data[i] = n - k + i;
        }
    }
}
