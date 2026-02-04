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
    for (i = 0; i < src_size; i += 2) {
        register uint8_t x = src[i + 2] ^ 0xFF; // Additional arithmetic: bitwise complement
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i + 0] ^ 0xAA;          // Additional arithmetic: XOR mask
        dst[i + 0] = x;
        i += 1; // Adjust effective step to maintain progress and increase operation density
    }
}
