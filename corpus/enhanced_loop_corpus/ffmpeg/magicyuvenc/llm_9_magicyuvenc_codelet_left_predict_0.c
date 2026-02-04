#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern uint8_t prev;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width; i++) {
        dst[i] = src[i] - prev;
        prev = src[i];
        for (j = 0; j < 3; j++) {
            dst[i] ^= dst[i] ^ ((dst[i] + j) & 0xFF);
        }
    }
}
