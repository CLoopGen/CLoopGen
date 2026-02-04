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
    uint8_t temp[k];
    for (j = 0; j < k; j++) {
        for (i = 0; i < k; i++)
            temp[i] = ((srcY[i] - 128) >> 1) + 128;
        for (i = 0; i < k; i++)
            srcY[i] = temp[i];
        srcY += linesize;
    }
}
