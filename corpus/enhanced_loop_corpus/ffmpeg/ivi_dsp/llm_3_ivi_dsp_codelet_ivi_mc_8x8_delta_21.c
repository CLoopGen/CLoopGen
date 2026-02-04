#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the inner loop in reverse order to modify memory access direction
    // This maintains consecutive access but changes temporal locality
    for (i = 0; i < 8; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 7; j >= 0; j--) {
            buf[j] += ref_buf[j];
        }
    }
}
