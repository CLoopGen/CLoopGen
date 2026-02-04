#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    uint8_t acc = 0;
    for (j = 0; j < bpp; j++) {
        acc += last[j]; 
        dst[j] = (acc >> 1) + src[j];
        acc = dst[j] & 0xFF; 
    }
}
