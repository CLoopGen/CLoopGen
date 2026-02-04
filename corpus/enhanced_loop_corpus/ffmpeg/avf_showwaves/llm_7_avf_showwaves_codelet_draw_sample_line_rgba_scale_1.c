#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[4];
    temp[0] = color[0]; temp[1] = color[1]; 
    temp[2] = color[2]; temp[3] = color[3];
    for (k = start; k < end; k++) {
        int idx = k * linesize;
        buf[idx + 0] = (buf[idx + 0] + temp[0]) & 0xFF;
        buf[idx + 1] = (buf[idx + 1] + temp[1]) & 0xFF;
        buf[idx + 2] = (buf[idx + 2] + temp[2]) & 0xFF;
        buf[idx + 3] = (buf[idx + 3] + temp[3]) & 0xFF;
        // Introduce artificial loop-carried dependency
        temp[0] = (temp[0] + 1) & 0x7F;
        temp[1] = (temp[1] + 1) & 0x7F;
        temp[2] = (temp[2] + 1) & 0x7F;
        temp[3] = (temp[3] + 1) & 0x7F;
    }
}
