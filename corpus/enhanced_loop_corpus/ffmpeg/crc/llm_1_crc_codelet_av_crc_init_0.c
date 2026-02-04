#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t AVCRC;

extern AVCRC *ctx;
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        ctx[256 * 1 + i] = (ctx[256 * 0 + i] >> 8) ^ ctx[ctx[256 * 0 + i] & 255];
        ctx[256 * 2 + i] = (ctx[256 * 1 + i] >> 8) ^ ctx[ctx[256 * 1 + i] & 255];
        ctx[256 * 3 + i] = (ctx[256 * 2 + i] >> 8) ^ ctx[ctx[256 * 2 + i] & 255];
    }
}
