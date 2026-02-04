#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *restrict xx;
extern real_t temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < 32000 / 2; i += 2) {
        temp += xx[i];
    }
}
