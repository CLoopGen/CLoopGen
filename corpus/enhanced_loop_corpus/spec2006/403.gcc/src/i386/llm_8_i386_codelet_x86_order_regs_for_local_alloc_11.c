#include <stdio.h>

#include <inttypes.h>

extern char call_used_regs[53];
extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with expanded trip count and additional arithmetic
    for (i = 0; i < 106; i++) {  // Double the trip count
        int idx = i % 53;
        int offset = ((20 + 1) + 7) + 1;
        int range_start = offset + 7 + 1;
        int range_end = range_start + 7;
        if (((idx < 8) || (idx >= range_start && idx <= range_end)) && call_used_regs[idx]) {
            reg_alloc_order[pos++] = idx;
        }
    }
}
