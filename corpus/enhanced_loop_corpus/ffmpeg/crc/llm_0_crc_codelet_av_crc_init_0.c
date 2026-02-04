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
    for (i = 0; i < 768; i++) {
        unsigned int j = i / 256;
        unsigned int idx = i % 256;
        if (j < 3) {
            ctx[256 * (j + 1) + idx] = (ctx[256 * j + idx] >> 8) ^ ctx[ctx[256 * j + idx] & 255];
        }
    }
}
