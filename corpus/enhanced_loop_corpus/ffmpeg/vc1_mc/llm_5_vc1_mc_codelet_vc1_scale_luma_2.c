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
        for (i = 0; i < k; i++) {
            if ((srcY[i] & 1) == 0) {
                srcY[i] = ((srcY[i] - 128) >> 1) + 128;
            } else {
                srcY[i] = ((srcY[i] - 128) + 1) / 2 + 128;
            }
        }
        srcY += linesize;
    }
}
