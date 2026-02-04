#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern uint16_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < w; j++) {
        if (j % 2 == 0) {
            dst[j] = src[-j];
        } else {
            dst[j] = 0;
        }
    }
}
