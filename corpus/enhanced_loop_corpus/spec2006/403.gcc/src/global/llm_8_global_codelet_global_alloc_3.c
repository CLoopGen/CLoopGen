#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and doubled trip count
    for (i = 0; i < 106; i++) {
        size_t idx = (i * i + 3 * i) % 53;
        reg_allocno[idx] = (int)(-1 - i % 5);
    }
}
