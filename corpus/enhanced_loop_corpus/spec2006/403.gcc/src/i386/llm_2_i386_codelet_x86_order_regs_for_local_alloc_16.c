#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 8; i <= (8 + 7); i++) {
        reg_alloc_order[pos] = i;
        pos += 2;  // Stride of 2 in destination array
    }
}
