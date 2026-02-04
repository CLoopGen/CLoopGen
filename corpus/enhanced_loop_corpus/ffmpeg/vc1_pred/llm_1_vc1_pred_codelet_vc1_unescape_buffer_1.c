#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = size / 2;
    int remainder = size % 2;
    dsize = 0;
    for (int o = 0; o < outer; o++) {
        *dst++ = *src++;
        dsize++;
        *dst++ = *src++;
        dsize++;
    }
    if (remainder) {
        *dst++ = *src++;
        dsize++;
    }
}
