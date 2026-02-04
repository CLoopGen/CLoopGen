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
for (i = 0; i < 2; i++, buf += dpitch * 2, wptr += pitch * 2, ref_buf += pitch * 2)
    for (j = 0; j < 4; j++)
        buf[j] += (ref_buf[j] + wptr[j]) >> 1;
}
