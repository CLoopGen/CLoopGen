#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with index remapping
    // Access pattern changed to write sequentially to pt, reading tt in strided manner
    for (i = 0; i <= 3; i++) {
        int idx_pt1 = i;
        int idx_pt2 = 7 - i;
        int idx_tt_even = 2 * i;
        int idx_tt_odd = 2 * i + 1;
        pt[idx_pt1] = tt[idx_tt_even];
        pt[idx_pt2] = tt[idx_tt_odd];
    }
}
