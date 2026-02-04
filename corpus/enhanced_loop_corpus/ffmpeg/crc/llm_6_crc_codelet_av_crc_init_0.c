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
    AVCRC temp[256];
    for (i = 0; i < 256; i++) {
        temp[i] = ctx[256 * 0 + i];
    }
    for (i = 0; i < 256; i++) {
        for (j = 1; j < 4; j++) {
            ctx[256 * j + i] = (temp[i] >> 8) ^ ctx[temp[i] & 255];
            temp[i] = ctx[256 * j + i];
        }
    }
}
