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
    int step;
    for (k = start; k < end; k++) {
        step = k * linesize;
        buf[step] += c0;
        buf[step] += c0;
        buf[step] += c0;
        buf[step] += c0;
    }
}
