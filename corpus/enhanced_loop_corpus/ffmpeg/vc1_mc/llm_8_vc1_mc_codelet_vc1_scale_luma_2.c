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
for (j = 0; j < k * k; j++) {
    for (i = 0; i < k; i++) {
        uint8_t val = srcY[i];
        val = ((val - 128) >> 1) + 128;
        val = ((val - 128) >> 1) + 128;
        srcY[i] = val;
    }
    if ((j + 1) % k == 0)
        srcY += linesize;
}
}
