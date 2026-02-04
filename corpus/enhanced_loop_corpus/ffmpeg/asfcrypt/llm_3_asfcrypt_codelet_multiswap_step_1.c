#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access but starting from a base offset
    int base = 3; // Base offset into the keys array
    for (i = 0; i < 4; i++) {
        v = (v >> 16) | (v << 16);
        v *= keys[base + i]; // Consecutive access: keys[3], keys[4], keys[5], keys[6]
    }
}
