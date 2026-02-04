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
    for (k = start; k < end; k += 2) {
        buf[k * linesize] += color[0];
        if (k + 1 < end)
            buf[(k + 1) * linesize] += color[0];
    }
}
