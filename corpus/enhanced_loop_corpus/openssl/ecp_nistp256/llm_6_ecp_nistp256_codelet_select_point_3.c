#include <stdio.h>

#include <inttypes.h>

typedef uint64_t u64;

typedef u64 smallfelem[4];

extern  u64 idx;
extern unsigned int size;
extern  smallfelem pre_comp[16][3];
extern unsigned int i;
extern unsigned int j;
extern u64 *outlimbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u64 temp[12]; // Local accumulator to remove WAW hazards on outlimbs
    for (i = 0; i < size; i++) {
        const u64 *inlimbs = (u64 *)&pre_comp[i][0][0];
        u64 mask = i ^ idx;
        mask |= mask >> 4;
        mask |= mask >> 2;
        mask |= mask >> 1;
        mask &= 1;
        mask--;
        // Introduce local dependency: each temp[j] depends on previous temp[j-1]
        temp[0] = inlimbs[0] & mask;
        for (j = 1; j < 4 * 3; j++) {
            temp[j] = (inlimbs[j] & mask) | (temp[j-1] >> 63); // RAW dependency chain
        }
    }
    // Write accumulated result once, reducing loop-carried WAW on outlimbs
    for (j = 0; j < 4 * 3; j++) {
        outlimbs[j] |= temp[j];
    }
}
