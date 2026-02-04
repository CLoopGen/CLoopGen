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
for (y = 0; y < 16; y++) {
    for (x = 0; x < 4; x++) {
        int index = (y & 7) * 8 + x * 2;
        block[index]     = tsrc[x * 2];
        block[index + 1] = tsrc[x * 2 + 1];
    }
    if (y % 2 == 1) tsrc += linesize >> 1;
}
}
