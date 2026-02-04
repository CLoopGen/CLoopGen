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
        int16_t prev_val = ref_buf[0];
        for (j = 0; j < 4; j++) {
            int16_t avg = (prev_val + ref_buf[j + 1]) >> 1;
            buf[j] += avg;
            prev_val = ref_buf[j + 1];
        }
    }
}
