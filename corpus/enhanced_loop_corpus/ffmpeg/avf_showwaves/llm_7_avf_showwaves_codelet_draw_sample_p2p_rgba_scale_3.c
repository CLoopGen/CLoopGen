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
    uint8_t temp_color[4];
    for (int i = 0; i < 4; i++) {
        temp_color[i] = color[i];
    }
    for (k = start + 1; k < end; k++) {
        int idx = k * linesize;
        buf[idx + 0] = buf[idx + 0] + temp_color[0];
        buf[idx + 1] = buf[idx + 1] + temp_color[1];
        buf[idx + 2] = buf[idx + 2] + temp_color[2];
        buf[idx + 3] = buf[idx + 3] + temp_color[3];
    }
}
