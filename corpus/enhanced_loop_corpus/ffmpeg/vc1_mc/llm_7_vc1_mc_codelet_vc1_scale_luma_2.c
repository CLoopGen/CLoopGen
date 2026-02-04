#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcY;
extern int k;
extern int linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < k; j++) {
        uint8_t offset = (j % 2) ? 64 : 192;
        for (i = 0; i < k; i++) {
            uint8_t val = srcY[i] - 128;
            val = (val >> 1) + offset;
            srcY[i] = val + (128 - offset);
        }
        srcY += linesize;
    }
}
