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
    int idx = j % k;
    if (idx == 0 && j != 0)
        srcY += linesize;
    srcY[idx] = ((srcY[idx] - 128) >> 1) + 128;
}
}
