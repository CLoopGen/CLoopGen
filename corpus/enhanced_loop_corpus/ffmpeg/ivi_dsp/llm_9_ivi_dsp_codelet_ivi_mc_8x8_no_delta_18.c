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
    for (i = 0; i < 4; i++, buf += dpitch * 2, ref_buf += pitch * 2)
        for (j = 0; j < 4; j++) {
            buf[j]           = (ref_buf[j] + ref_buf[j + 1]) >> 1;
            buf[j + 4]       = (ref_buf[j + 8] + ref_buf[j + 9]) >> 1;
            (buf + dpitch)[j]       = (ref_buf[j + pitch] + ref_buf[j + pitch + 1]) >> 1;
            (buf + dpitch)[j + 4]   = (ref_buf[j + pitch + 8] + ref_buf[j + pitch + 9]) >> 1;
        }
}
