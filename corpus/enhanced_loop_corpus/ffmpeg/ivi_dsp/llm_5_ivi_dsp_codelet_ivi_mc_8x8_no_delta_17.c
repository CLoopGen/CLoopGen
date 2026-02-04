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
        for (j = 0; j < 8; j++) {
            if ((i + j) % 3 != 0) {
                buf[j] = ref_buf[j];
            }
        }
    }
}
