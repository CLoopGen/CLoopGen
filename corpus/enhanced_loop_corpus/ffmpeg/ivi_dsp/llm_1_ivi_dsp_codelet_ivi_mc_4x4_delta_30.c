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
    for (i = 0; i < 4; i++, buf += dpitch) {
        j = 0;
        (buf[j]) += ((ref_buf[j] + ref_buf[j + 1]) >> 1);
        j = 1;
        (buf[j]) += ((ref_buf[j] + ref_buf[j + 1]) >> 1);
        j = 2;
        (buf[j]) += ((ref_buf[j] + ref_buf[j + 1]) >> 1);
        j = 3;
        (buf[j]) += ((ref_buf[j] + ref_buf[j + 1]) >> 1);
        ref_buf += pitch;
    }
}
