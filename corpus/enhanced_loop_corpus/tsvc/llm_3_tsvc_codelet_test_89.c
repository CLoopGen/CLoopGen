#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *A;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (int i = 3; i >= 0; i--)
        s += A[i];
}
