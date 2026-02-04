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
extern  int16_t *wptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using fixed offsets with stride simulation
    ptrdiff_t b_offset = 0;
    ptrdiff_t r_offset = 0;
    ptrdiff_t w_offset = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            // Use strided access by scaling index with a fixed step (simulating non-unit stride)
            ptrdiff_t idx = j * 2; // Simulate strided access (every other element)
            if (idx + 1 < 8) { // Ensure we don't go out of bounds
                int16_t avg = (ref_buf[r_offset + idx] + ref_buf[r_offset + idx + 1] +
                               wptr[w_offset + idx] + wptr[w_offset + idx + 1]) >> 2;
                buf[b_offset + idx] += avg;
            }
        }
        b_offset += dpitch;
        r_offset += pitch;
        w_offset += pitch;
    }
}
