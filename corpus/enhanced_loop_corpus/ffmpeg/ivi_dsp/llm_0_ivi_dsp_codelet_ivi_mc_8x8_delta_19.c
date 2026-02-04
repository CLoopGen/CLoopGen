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
        int idx = i % 8;
        int offset = i / 8;
        buf[idx + offset * dpitch] += ((ref_buf[idx + offset * pitch] + wptr[idx + offset * pitch]) >> 1);
    }
}
