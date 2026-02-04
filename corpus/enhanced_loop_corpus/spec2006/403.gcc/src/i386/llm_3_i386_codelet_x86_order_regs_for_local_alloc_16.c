#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index offset array
    int offsets[] = {0, 1, 2, 3, 4, 5, 6, 7};  // Index offsets for indirect write
    for (i = 0; i < 8; i++) {
        reg_alloc_order[pos + offsets[i]] = 8 + i;
    }
    pos += 8;  // Advance pos by total elements written
}
