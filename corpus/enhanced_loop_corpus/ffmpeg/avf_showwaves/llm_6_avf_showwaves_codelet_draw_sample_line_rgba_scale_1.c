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
    uint8_t c0 = color[0];
    uint8_t c1 = color[1];
    uint8_t c2 = color[2];
    uint8_t c3 = color[3];
    for (k = start; k < end; k++) {
        int index = k * linesize;
        buf[index + 0] += c0;
        buf[index + 1] += c1;
        buf[index + 2] += c2;
        buf[index + 3] += c3;
    }
}
