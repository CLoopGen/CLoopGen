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
    for (i = 0; i < 8; ++i, buf += dpitch, wptr += pitch, ref_buf += pitch) {
        if (i % 2 == 0) {
            for (j = 0; j < 8; ++j) {
                buf[j] += (ref_buf[j] + wptr[j]) >> 1;
            }
        } else {
            for (j = 0; j < 8; ++j) {
                if (ref_buf[j] != 0 || wptr[j] != 0) {
                    buf[j] += (ref_buf[j] + wptr[j] + 1) >> 1;
                }
            }
        }
    }
}
