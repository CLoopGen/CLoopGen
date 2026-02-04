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
        int row = i / 4;
        int col = i % 4;
        buf[col + row * dpitch] += ((ref_buf[col + row * pitch] + ref_buf[col + row * pitch + 1] + 
                                   wptr[col + row * pitch] + wptr[col + row * pitch + 1]) >> 2);
    }
}
