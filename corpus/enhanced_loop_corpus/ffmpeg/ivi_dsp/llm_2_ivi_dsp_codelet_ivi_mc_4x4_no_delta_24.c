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
    // Variant 1: Consecutive memory access with manual offset calculation to improve spatial locality
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int idx = j;
            b[idx] = (r[idx] + r[idx + 1] + w[idx] + w[idx + 1]) >> 2;
        }
        b += dpitch;
        r += pitch;
        w += pitch;
    }
}
