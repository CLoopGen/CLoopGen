#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int start = ((20 + 1) + 7) + 1;
    int end = start + 7;
    for (i = start; i <= end; i += 2)
        reg_alloc_order[pos++] = i;
}
