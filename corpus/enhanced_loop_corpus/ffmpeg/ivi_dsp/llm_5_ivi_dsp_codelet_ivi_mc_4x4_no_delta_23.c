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
    for (i = 0; i < 4; i++, buf += dpitch, wptr += pitch, ref_buf += pitch)
        for (j = 0; j < 4; j++) {
            int16_t sum = ref_buf[j] + wptr[j];
            if (sum >= 0) {
                buf[j] = sum >> 1;
            } else {
                buf[j] = -((-sum) >> 1);
            }
        }
}
