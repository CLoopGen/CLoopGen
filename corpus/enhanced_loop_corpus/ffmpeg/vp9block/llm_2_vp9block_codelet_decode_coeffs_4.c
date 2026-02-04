#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled by 2 for adjacent elements)
    // Instead of accessing every 2nd element in strided pattern, process two consecutive bytes at a time
    // using aligned 16-bit load and update both bytes based on the 16-bit value.
    for (n = 0; n < end_y - 1; n += 2) {
        uint16_t val = ((const av_alias16 *)(&l[n]))->u16;
        l[n]     = !!(val);
        l[n + 1] = !!(val);
    }
    // Handle potential last odd index if end_y is odd
    if (n == end_y - 1) {
        l[n] = !!(l[n]);
    }
}
