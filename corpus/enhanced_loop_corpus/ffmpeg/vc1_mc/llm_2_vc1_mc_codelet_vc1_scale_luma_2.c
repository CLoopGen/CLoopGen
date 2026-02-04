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
    // Variant 1: Consecutive memory access using pointer arithmetic with stride simulation
    uint8_t *temp_srcY = srcY;
    for (j = 0; j < k; j++) {
        for (i = 0; i < k; i++) {
            int index = i;
            temp_srcY[index] = ((temp_srcY[index] - 128) >> 1) + 128;
        }
        temp_srcY += linesize;
    }
}
