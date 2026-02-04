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
    int i, j, k;
    for (k = 0; k < 8; k++) {
        for (i = 0; i < 1; i++) {
            for (j = 0; j < 8; j++) {
                (buf[j]) += ((ref_buf[j] + ref_buf[j + 1]) >> 1);
            }
            buf += dpitch;
            ref_buf += pitch;
        }
    }
}
