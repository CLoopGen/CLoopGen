#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *A;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (accessing even indices only)
    for (int i = 0; i < 8; i += 2) {
        if (i/2 < 4)  // Ensures we only add 4 elements as in original
            s += A[i];
    }
}
