#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled trip count
    int start = 20 + 1 + 7 + 1 + 7 + 1 + 7 + 1;
    int end = start + 14;  // Double the original step range (originally +7, now +14)
    for (i = start; i <= end; i++) {
        int temp = i * i + 3 * i - 5;  // Added polynomial computation
        reg_alloc_order[pos++] = temp;
    }
}
