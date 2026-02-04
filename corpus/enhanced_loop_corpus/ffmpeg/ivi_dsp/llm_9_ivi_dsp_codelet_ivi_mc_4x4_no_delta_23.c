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
    for (i = 0; i < 2; i++, buf += dpitch, wptr += pitch, ref_buf += pitch)
        for (j = 0; j < 4; j++) {
            int16_t avg1 = (ref_buf[j] + wptr[j]) >> 1;
            int16_t avg2 = (ref_buf[j+1] + wptr[j+1]) >> 1;
            buf[j] = avg1;
            buf[j+1] = avg2;
        }
}
