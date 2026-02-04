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
    // Variant 2: Strided access with increased stride (every 4th byte instead of every 2nd)
    // Simulates sparse sampling of memory with larger step, still aligning to 16-bit boundary
    const int stride = 4;
    for (n = 0; n < end_y - 1; n += stride) {
        l[n] = !!(((const av_alias16 *)(&l[n]))->u16);
    }
    // Final pass on last possible aligned 16-bit chunk if within bounds
    if (n == end_y - 2) {
        l[n] = !!(((const av_alias16 *)(&l[n]))->u16);
    } else if (n < end_y) {
        l[n] = !!(l[n]);
    }
}
