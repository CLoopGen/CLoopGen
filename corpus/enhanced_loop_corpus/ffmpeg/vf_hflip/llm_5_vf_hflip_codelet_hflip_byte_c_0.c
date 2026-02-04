#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int w;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < w; j++) {
        if (j >= w / 2) {
            dst[j] = src[-j];
        } else {
            dst[j] = 0;
        }
    }
}
