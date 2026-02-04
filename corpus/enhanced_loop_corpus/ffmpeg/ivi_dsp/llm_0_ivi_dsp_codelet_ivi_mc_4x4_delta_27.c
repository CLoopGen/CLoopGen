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
    for (i = 0; i < 16; i++) {
        int idx = i % 4;
        int step = i / 4;
        buf[idx] += ((ref_buf[idx] + wptr[idx]) >> 1);
        if (idx == 3 && step < 3) {
            buf += dpitch;
            wptr += pitch;
            ref_buf += pitch;
        }
    }
}
