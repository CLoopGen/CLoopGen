#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset alignment
    // Instead of strided access by 2, process consecutive elements starting from index 3
    for (i = 3; i < 42; i++)
        dst[i] = src[i];
}
