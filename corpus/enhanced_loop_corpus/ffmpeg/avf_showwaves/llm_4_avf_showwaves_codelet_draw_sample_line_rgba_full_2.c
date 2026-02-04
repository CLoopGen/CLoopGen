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
    for (k = start; k < end; k++) {
        int offset = k * linesize;
        if ((k - start) % 2 == 0) {
            buf[offset + 0] = color[0];
            buf[offset + 1] = color[1];
            buf[offset + 2] = color[2];
            buf[offset + 3] = color[3];
        }
    }
}
