#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with forward iteration
    int base = (20 + 1);
    for (i = 0; i <= 7; i += 2)
        reg_alloc_order[pos + (i / 2)] = base + i;
}
