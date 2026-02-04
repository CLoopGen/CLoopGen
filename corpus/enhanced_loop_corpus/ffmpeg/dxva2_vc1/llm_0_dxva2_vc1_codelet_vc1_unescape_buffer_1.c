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
    int outer_loop_bound = size / 2;
    int remainder = size % 2;
    for (int i = 0; i < outer_loop_bound; i++) {
        *dst++ = *src++;
        *dst++ = *src++;
    }
    for (int j = 0; j < remainder; j++) {
        *dst++ = *src++;
    }
}
