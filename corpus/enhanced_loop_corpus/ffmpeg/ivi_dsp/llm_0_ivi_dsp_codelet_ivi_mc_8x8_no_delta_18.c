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
    int i, j;
    for (i = 0; i < 64; i++) {
        int row = i >> 3;
        int col = i & 7;
        if (col == 0 && row > 0) {
            buf += dpitch;
            ref_buf += pitch;
        }
        buf[col] = (ref_buf[col] + ref_buf[col + 1]) >> 1;
    }
}
