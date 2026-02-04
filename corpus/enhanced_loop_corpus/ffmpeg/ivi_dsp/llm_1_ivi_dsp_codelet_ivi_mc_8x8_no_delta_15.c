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
    for (i = 0; i < 64; i++) {
        int j = i & 7;
        if (j == 0 && i > 0) {
            buf += dpitch;
            wptr += pitch;
            ref_buf += pitch;
        }
        buf[j] = (ref_buf[j] + wptr[j]) >> 1;
    }
}
