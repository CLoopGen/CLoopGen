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
        int16_t prev_val = ref_buf[0];
        for (j = 0; j < 8; j++) {
            int16_t curr_val = ref_buf[j];
            int16_t avg = (prev_val + curr_val) >> 1;
            buf[j] += avg;
            prev_val = curr_val;
        }
    }
}
