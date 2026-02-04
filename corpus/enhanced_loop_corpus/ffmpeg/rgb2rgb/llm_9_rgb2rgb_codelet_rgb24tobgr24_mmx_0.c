#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size; i += 9) {
        register uint8_t x;
        dst[i + 1] = src[i + 1] ^ 0xFF;
        dst[i + 2] = src[i + 0] ^ 0xAA;
        x = src[i + 2] ^ 0x55;
        dst[i + 0] = x;
        if (i + 3 < src_size) {
            dst[i + 4] = src[i + 4];
            dst[i + 5] = src[i + 3];
            dst[i + 3] = src[i + 5];
        }
        if (i + 6 < src_size) {
            dst[i + 7] = src[i + 7];
            dst[i + 8] = src[i + 6];
            dst[i + 6] = src[i + 8];
        }
    }
}
