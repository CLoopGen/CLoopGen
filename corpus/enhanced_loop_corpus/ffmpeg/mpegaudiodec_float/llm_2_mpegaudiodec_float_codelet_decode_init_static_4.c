#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    float *ptr0 = &is_table[0][7];
    float *ptr1 = &is_table[1][7];
    for (i = 0; i < 9; i++) {
        *(ptr0 + i) = *(ptr1 + i) = 0.0f;
    }
}
