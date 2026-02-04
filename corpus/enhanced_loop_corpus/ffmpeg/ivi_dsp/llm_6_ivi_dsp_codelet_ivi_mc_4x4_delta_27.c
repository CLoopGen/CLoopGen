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
    int16_t temp[4];
    for (i = 0; i < 4; i++, buf += dpitch, wptr += pitch, ref_buf += pitch) {
        for (j = 0; j < 4; j++) {
            temp[j] = (ref_buf[j] + wptr[j]) >> 1;
        }
        for (j = 0; j < 4; j++) {
            buf[j] += temp[j];
        }
    }
}
