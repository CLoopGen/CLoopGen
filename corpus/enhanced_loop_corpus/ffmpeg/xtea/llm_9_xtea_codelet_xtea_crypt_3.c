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
    for (i = 0; i < 4; i += 2) {
        dst[i]     = src[i] ^ iv[i] ^ 0xAA;
        dst[i + 1] = src[i + 1] ^ iv[i + 1] ^ 0x55;
    }
}
