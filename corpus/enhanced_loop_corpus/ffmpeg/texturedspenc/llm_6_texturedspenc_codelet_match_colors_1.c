#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t mask;
extern int dots[16];
extern int x;
extern int c0_point;
extern int half_point;
extern int c3_point;
extern  int indexMap[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_mask = mask;
    for (x = 0; x < 16; x++) {
        int dot = dots[x];
        int bits = (dot < half_point ? 4 : 0) | (dot < c0_point ? 2 : 0) | (dot < c3_point ? 1 : 0);
        local_mask >>= 2;
        local_mask |= ((uint32_t)indexMap[bits]) << 30;  // Shift to avoid immediate overwrite in next iteration
    }
    mask = local_mask;  // Single write to shared state after loop (removes WAW and RAW hazards across iterations)
}
