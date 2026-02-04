#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern  int start;
extern  int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = start; k < end; k++) {
        int base = k * linesize;
        buf[base + 3] = color[3];
        buf[base + 2] = color[2];
        buf[base + 1] = color[1];
        buf[base + 0] = color[0]; // Reverse order introduces WAW-like pattern per element, but no loop-carried dep
    }
}
