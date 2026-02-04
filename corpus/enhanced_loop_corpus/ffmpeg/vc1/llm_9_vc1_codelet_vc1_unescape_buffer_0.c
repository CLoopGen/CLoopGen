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
        if (i + 2 < size && src[-1] == 3 && i >= 1 && !src[-2] && !src[-3] && src[0] < 4) {
            dst[dsize++] = src[0];
            step = 2;
        } else if (i < size) {
            dst[dsize++] = src[-1];
        }
    }
}
