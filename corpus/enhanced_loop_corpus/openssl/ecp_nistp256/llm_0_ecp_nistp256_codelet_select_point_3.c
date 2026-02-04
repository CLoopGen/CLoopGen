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
for (i = 0; i < size; i++) {
    const u64 *inlimbs = (u64 *)&pre_comp[i][0][0];
    u64 mask = i ^ idx;
    mask |= mask >> 4;
    mask |= mask >> 2;
    mask |= mask >> 1;
    mask &= 1;
    mask--;
    for (j = 0; j < 4 * 3; j++) {
        outlimbs[j] |= inlimbs[j] & mask;
    }
}
}
