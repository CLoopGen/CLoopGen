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
    // Variant 2: Consecutive Block Memory Access Pattern
    // Reorder inner loop to process two elements at once and promote spatial locality
    // Also use temporary variables to reduce repeated memory accesses
    int16_t *b, *r, *w;
    for (i = 0; i < 8; i++, buf += dpitch, wptr += pitch, ref_buf += pitch) {
        b = buf; r = ref_buf; w = wptr;
        for (j = 0; j < 8; j += 2) {
            // Process two consecutive elements together
            int16_t avg1 = ((r[j] + r[j+1] + w[j] + w[j+1]) >> 2);
            int16_t avg2 = ((r[j+1] + r[j+2] + w[j+1] + w[j+2]) >> 2);
            b[j] = avg1;
            if (j + 1 < 8) b[j+1] = avg2;
        }
    }
}
