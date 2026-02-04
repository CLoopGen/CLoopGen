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
    int i, j, k;
    for (k = 0; k < 2; k++)
        for (i = 0; i < 2; i++)
            for (j = 0; j < 4; j++) {
                int idx = i * 4 + j;
                buf[idx] = (ref_buf[idx] + wptr[idx]) >> 1;
            }
}
