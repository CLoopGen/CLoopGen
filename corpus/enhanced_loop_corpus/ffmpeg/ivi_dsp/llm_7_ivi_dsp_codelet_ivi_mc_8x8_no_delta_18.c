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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++, buf += dpitch, ref_buf += pitch) {
        buf[0] = (ref_buf[0] + ref_buf[1]) >> 1;
        for (j = 1; j < 8; j++) {
            buf[j] = (buf[j - 1] + ref_buf[j] + ref_buf[j + 1]) >> 2;
        }
    }
}
