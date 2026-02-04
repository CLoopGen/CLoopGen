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
    for (i = 0; i < 4; i++) {
        dst[i +  0] = src[i +  0] ^ iv[i +  0];
        dst[i +  4] = src[i +  4] ^ iv[i +  4];
        dst[i +  8] = src[i +  8] ^ iv[i +  8];
        dst[i + 12] = src[i + 12] ^ iv[i + 12];
    }
}
