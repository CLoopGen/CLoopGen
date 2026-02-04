#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *arr;
extern int length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element forward, then second pass for odd indices)
    int stride = 2;
    for (int phase = 0; phase < stride; phase++) {
        for (int i = phase; i < length; i += stride) {
            arr[i] = 1. / (real_t)(i + 1);
        }
    }
}
