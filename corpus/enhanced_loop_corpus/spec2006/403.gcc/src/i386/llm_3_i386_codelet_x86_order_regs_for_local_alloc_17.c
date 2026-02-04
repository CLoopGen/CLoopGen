#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated statically)
    int indices[8] = {8, 9, 10, 11, 12, 13, 14, 15};
    for (i = 0; i < 8; i++)
        reg_alloc_order[pos++] = indices[i];
}
