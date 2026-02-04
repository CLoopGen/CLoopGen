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
        for (x = 0; x < 8; x++) {
            if (x < 4)
                block[y * 8 + x] = tsrc[x] + 1;
            else
                block[y * 8 + x] = tsrc[x] - 1;
        }
        tsrc += linesize >> 1;
    }
}
