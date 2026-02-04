#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *dst;
extern int stride;
extern int bits;
extern int i;
extern int x;
extern int Ra;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_x = x;
    for (i = 0; i < r; i++) {
        int offset = i * (stride / (bits == 8 ? 1 : 2)); // Eliminate loop-carried dependency on x, compute independently
        if (bits == 8) {
            ((uint8_t *)(dst))[offset] = Ra;
        } else {
            ((uint16_t *)(dst))[offset] = Ra;
        }
    }
    x = local_x + r * stride; // Update x after loop (no intra-loop dependency on prior x)
}
