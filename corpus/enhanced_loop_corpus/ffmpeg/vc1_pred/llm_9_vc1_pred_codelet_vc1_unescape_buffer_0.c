#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (i = 0; i < size; i += step) {
        step = 1;
        src += step;
        if (src[-step] == 3 && i >= 2 && !src[-2] && !src[-3] && i < size - 1 && src[0] < 4) {
            dst[dsize++] = src[0];
            step = 2;
            src++;
            i++;
        } else {
            dst[dsize++] = src[-step];
        }
        if (dsize >= size) break;
    }
}
