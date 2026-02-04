#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t accumulator = 0;
    for (i = 0; i < 16; i++) {
        accumulator ^= src[i] ^ iv[i];
        dst[i] = accumulator;
    }
}
