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
    for (i = 0; i < 64; i++) {
        int row = i / 8;
        int col = i % 8;
        buf[col] += (tmp[i] >> 1);
        if (col == 7) buf += pitch;
    }
}
