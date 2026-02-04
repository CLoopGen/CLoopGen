#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize;
extern int16_t *block;
extern int x;
extern int y;
extern  uint16_t *tsrc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        block[y * 8 + 0] = tsrc[0];
        block[y * 8 + 1] = tsrc[1];
        block[y * 8 + 2] = tsrc[2];
        block[y * 8 + 3] = tsrc[3];
        block[y * 8 + 4] = tsrc[4];
        block[y * 8 + 5] = tsrc[5];
        block[y * 8 + 6] = tsrc[6];
        block[y * 8 + 7] = tsrc[7];
        tsrc += linesize >> 1;
    }
}
