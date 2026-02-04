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
    for (int outer = start + 1; outer < end; outer++) {
        for (k = outer; k <= outer && k < end; k++)
            buf[k * linesize] += color[0];
    }
}
