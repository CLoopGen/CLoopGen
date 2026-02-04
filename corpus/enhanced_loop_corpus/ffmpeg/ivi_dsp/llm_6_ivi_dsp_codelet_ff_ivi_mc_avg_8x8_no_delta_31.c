#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_buf = buf;
    ptrdiff_t local_pitch = pitch;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            local_buf[j] = (tmp[i * 8 + j] >> 1);
        }
        local_buf += local_pitch;
    }
}
