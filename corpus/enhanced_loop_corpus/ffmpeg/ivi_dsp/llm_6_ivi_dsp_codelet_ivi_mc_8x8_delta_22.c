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
    int16_t *temp_buf = buf;
    int16_t *temp_ref = ref_buf;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 7; j++) {
            int16_t pred = (ref_buf[j] + ref_buf[j + 1]) >> 1;
            buf[j] += pred;
        }
        buf += dpitch;
        ref_buf += pitch;
    }
    buf = temp_buf;
    ref_buf = temp_ref;
    for (i = 0; i < 8; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 0; j < 8; j++) {
            buf[j] += (ref_buf[j] + ref_buf[j + pitch]) >> 1;
        }
    }
}
