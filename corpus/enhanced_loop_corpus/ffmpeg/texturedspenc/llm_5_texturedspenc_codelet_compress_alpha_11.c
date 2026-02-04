#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern int dist;
extern int bias;
extern int dist4;
extern int dist2;
extern int bits;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int alp = block[3 + x * 4 + y * stride] * 7 + bias;
        int ind = 0;

        // Fully branchless computation using bitwise and comparison masks
        int gt_mask = -(alp >= dist4);
        ind += gt_mask & 4;
        alp -= gt_mask & dist4;

        gt_mask = -(alp >= dist2);
        ind += gt_mask & 2;
        alp -= gt_mask & dist2;

        ind += -(alp >= dist) & 1;
        ind = (-ind & 7) ^ (-(2 > ind) & 1);  // Branchless version of XOR condition

        mask |= ind << bits;
        bits += 3;

        // Unrolled store logic without branching
        uint8_t should_flush = (bits >= 8);
        *dst++ = should_flush ? (uint8_t)mask : *dst;
        dst = (uint8_t*)((ptrdiff_t)dst - should_flush);  // Undo increment if no flush
        mask = should_flush ? (mask >> 8) : mask;
        bits = should_flush ? (bits - 8) : bits;
    }
}
}
