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
    uint8_t local_color = color[0];
    for (k = start + 1; k < end; k++) {
        buf[k * linesize] = buf[(k-1) * linesize] + local_color;
    }
}
