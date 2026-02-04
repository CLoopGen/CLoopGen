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
    uint8_t *temp_srcY = srcY;
    int offset;
    for (j = 0; j < k; j += 2) {
        offset = j * linesize;
        for (i = 0; i < k; i++) {
            temp_srcY[offset + i] = lut1[temp_srcY[offset + i]];
        }
        if (j + 1 == k)
            break;
        offset += linesize;
        for (i = 0; i < k; i++) {
            temp_srcY[offset + i] = lut2[temp_srcY[offset + i]];
        }
    }
}
