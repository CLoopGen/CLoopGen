#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and doubled trip count
    int start = (20 + 1 + 7 + 1) * 2;
    int end = start + 15;
    for (i = start; i <= end; i += 2) {
        reg_alloc_order[pos++] = i * i + 3 * i - 2;
        reg_alloc_order[pos++] = i * (i - 1);
    }
}
