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
    int outer_limit = size / 2;
    int remainder = size % 2;
    for (int i = 0; i < outer_limit; i++) {
        *dst++ = *src++;
        *dst++ = *src++;
    }
    for (int i = 0; i < remainder; i++) {
        *dst++ = *src++;
    }
}
