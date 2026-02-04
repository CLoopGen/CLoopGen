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
        for (ptrdiff_t offset = 0; offset < 8; offset++) {
            block[y * 8 + offset] = tsrc[offset];
        }
        tsrc += linesize >> 1;
    }
}
