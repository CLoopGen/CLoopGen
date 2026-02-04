#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcY;
extern uint8_t *lut1;
extern uint8_t *lut2;
extern int k;
extern int linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < k; j++) {
    for (i = 0; i < k; i++)
        srcY[i] = lut1[srcY[i]];
    srcY += linesize;
}
}
