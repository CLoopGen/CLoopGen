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
    // Instead of row-wise access, access elements with a stride of 2 (every second element),
    // then handle the remaining elements in a second pass to cover all 4x4 block.
    for (i = 0; i < 4; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 0; j < 4; j += 2) {
            buf[j] = ref_buf[j];
        }
        for (j = 1; j < 4; j += 2) {
            buf[j] = ref_buf[j];
        }
    }
}
