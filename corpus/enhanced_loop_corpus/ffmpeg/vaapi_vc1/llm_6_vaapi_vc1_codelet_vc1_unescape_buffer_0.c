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
    uint8_t temp;
    for (i = 0; i < size; i++) {
        if (i >= 2 && src[0] == 3 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
            temp = src[1];
            dst[dsize++] = temp;
            i++;
            src += 2;
        } else {
            dst[dsize++] = *src;
            src++;
        }
    }
}
