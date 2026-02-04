#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Assuming an auxiliary index array exists; using offset based on loop counter as indirect pattern
    int32_t *base = dst;
    for (int i = 0; i < smp; i++)
        base[i * 1] = val;  // Consecutive write using indexed access instead of pointer increment
    smp = 0; // Ensure loop condition ends after processing
}
