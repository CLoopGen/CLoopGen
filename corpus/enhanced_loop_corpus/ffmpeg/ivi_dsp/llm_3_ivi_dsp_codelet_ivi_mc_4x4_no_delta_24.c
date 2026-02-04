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
    // Variant 2: Strided memory access – process elements with a fixed stride of 2, then handle remainder
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    for (i = 0; i < 4; i++) {
        // Stride-2 access pattern for improved cache behavior or vectorization potential
        for (j = 0; j < 4; j += 2) {
            // Process two consecutive elements with stride logic
            b[j] = (r[j] + r[j + 1] + w[j] + w[j + 1]) >> 2;
            if (j + 1 < 4) {
                b[j + 1] = (r[j + 1] + r[j + 2] + w[j + 1] + w[j + 2]) >> 2;
            }
        }
        b += dpitch;
        r += pitch;
        w += pitch;
    }
}
