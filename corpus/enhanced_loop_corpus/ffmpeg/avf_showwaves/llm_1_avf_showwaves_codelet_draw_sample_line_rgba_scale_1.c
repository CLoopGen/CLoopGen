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
    if (start < end) {
        for (int j = 0; j < 4; j++) {
            for (k = start; k < end; k++) {
                buf[k * linesize + j] += color[j];
            }
        }
    }
}
