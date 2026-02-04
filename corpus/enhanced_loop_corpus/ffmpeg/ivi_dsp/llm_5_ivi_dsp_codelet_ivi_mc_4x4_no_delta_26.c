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
    for (i = 0; i < 4; i++, buf += dpitch, ref_buf += pitch) {
        int skip_first = (i & 1);
        for (j = skip_first; j < 4; j++) {
            if (j < 3 || i == 0) {
                buf[j] = (ref_buf[j] + ref_buf[j + 1]) >> 1;
            } else {
                buf[j] = ref_buf[j];
            }
        }
        if (skip_first) {
            buf[0] = (ref_buf[0] + ref_buf[1] + 1) >> 1;
        }
    }
}
