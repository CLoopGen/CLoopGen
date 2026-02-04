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
    // Variant 1: Consecutive memory access with local pointers and unrolled accumulation
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    for (i = 0; i < 4; i++) {
        int16_t *b_row = b;
        int16_t *r_row = r;
        int16_t *w_row = w;
        // Process 4 elements with consecutive access pattern
        for (j = 0; j < 4; j += 2) {
            // Unroll two iterations and use consecutive accesses where possible
            if (j + 1 < 4) {
                int16_t avg1 = (r_row[j] + r_row[j+1] + w_row[j] + w_row[j+1]) >> 2;
                int16_t avg2 = (r_row[j+1] + r_row[j+2] + w_row[j+1] + w_row[j+2]) >> 2;
                b_row[j]   += avg1;
                b_row[j+1] += avg2;
            } else {
                int16_t avg = (r_row[j] + r_row[j+1] + w_row[j] + w_row[j+1]) >> 2;
                b_row[j] += avg;
            }
        }
        b += dpitch;
        r += pitch;
        w += pitch;
    }
}
