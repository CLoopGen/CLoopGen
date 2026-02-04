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
for (j = 0; j < k; j += 2) {
    for (i = 0; i < k; i += 2) {
        srcY[i]     = ((srcY[i]     - 128) >> 1) + 128;
        if (i + 1 < k)
            srcY[i+1] = ((srcY[i+1] - 128) >> 1) + 128;
    }
    if (j + 1 < k) {
        srcY += linesize;
        for (i = 0; i < k; i++)
            srcY[i] = ((srcY[i] - 128) >> 1) + 128;
        srcY += linesize;
    } else {
        srcY += linesize;
    }
}
}
