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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive j indices, access with a stride of 2 (every other element)
    // We still process 4 elements but in a strided manner, assuming buffer size allows it.
    for (i = 0; i < 4; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 0; j < 8; j += 2) {  // Stride of 2 over an extended range to get 4 effective writes
            buf[j] += ref_buf[j];
        }
    }
}
