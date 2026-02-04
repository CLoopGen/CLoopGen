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
    int factor = (end - start) > 16 ? 4 : 1;
    for (k = start; k < end; k++) {
        int base = k * linesize;
        uint8_t c0 = color[0], c1 = color[1], c2 = color[2], c3 = color[3];
        for (int f = 0; f < factor; f++) {
            buf[base + f] = (f % 4 == 0) ? c0 : (f % 4 == 1) ? c1 : (f % 4 == 2) ? c2 : c3;
        }
    }
}
