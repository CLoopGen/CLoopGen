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
        if (i % 3 == 0 && i >= 2 && src[0] == 3 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            dst[dsize++] = src[1] + 1;
            dst[dsize++] = src[1] + 2;
            src += 2;
            step = 2;
        } else {
            dst[dsize++] = *src;
            src++;
        }
    }
}
