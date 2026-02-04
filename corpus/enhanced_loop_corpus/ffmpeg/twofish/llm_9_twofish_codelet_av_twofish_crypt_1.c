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
    for (i = 0; i < 8; i++) {
        dst[i]       = src[i] ^ iv[i] ^ 0x55;
        dst[15 - i]  = src[15 - i] ^ iv[15 - i] ^ 0xAA;
    }
}
