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
    int step, limit = size >> 1;
    for (i = 0; i < limit; i += 2, src += 2) {
        step = 1;
        if (i + 1 < size) {
            if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
                dst[dsize++] = src[1];
                step = 2;
            } else if (src[1] == 3 && i + 1 >= 2 && !src[0] && !src[-1] && i + 1 < size - 1 && src[2] < 4) {
                dst[dsize++] = *src;
                dst[dsize++] = src[2];
                src++;
                i++;
                step = 2;
            } else {
                dst[dsize++] = *src;
                dst[dsize++] = src[1];
            }
        } else {
            dst[dsize++] = *src;
        }
        i += step - 1;
    }
    while (i < size) {
        dst[dsize++] = *src++;
        i++;
    }
}
