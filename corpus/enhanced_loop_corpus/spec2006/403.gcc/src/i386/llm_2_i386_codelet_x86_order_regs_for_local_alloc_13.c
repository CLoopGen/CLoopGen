#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed order
    int start = (20 + 1);
    int end = start + 7;
    for (i = end; i >= start; i--)
        reg_alloc_order[--pos] = i;
}
