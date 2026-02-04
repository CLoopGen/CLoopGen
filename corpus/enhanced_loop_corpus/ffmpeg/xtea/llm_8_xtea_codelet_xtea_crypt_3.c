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
    for (i = 0; i < 16; i++) {
        dst[i % 8] = src[i % 8] ^ iv[i % 8] ^ (src[(7 - (i % 8))] ^ 0x55);
    }
}
