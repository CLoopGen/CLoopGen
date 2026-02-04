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
        for (j = 0; j < 3; j++) {
            if (ctx[256 * j + i] != 0) {
                ctx[256 * (j + 1) + i] = (ctx[256 * j + i] >> 8) ^ ctx[ctx[256 * j + i] & 255];
            } else {
                ctx[256 * (j + 1) + i] = 0;
            }
        }
    }
}
