#include <stdio.h>

#include <inttypes.h>

extern unsigned long pow2_numbits;
extern unsigned long pow2_flag;
extern int j;
extern int pow2_shifts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using an array to simulate bit checking
    unsigned long numbits_copy = pow2_numbits;
    int shifts_array[64] = {0}; // Simulate consecutive storage of shift contributions
    for (j = 0; j < (8 * 8); j++) {
        unsigned long flag = numbits_copy & 1;
        shifts_array[j] = (int)flag;
        numbits_copy >>= 1;
    }
    // Accumulate after the fact to maintain semantic similarity
    for (j = 0; j < (8 * 8); j++) {
        pow2_shifts += shifts_array[j];
    }
}
