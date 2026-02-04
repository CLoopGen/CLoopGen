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
    AVCRC temp1, temp2;
    for (j = 0; j < 3; j++) {
        temp1 = ctx[256 * j + i];
        temp2 = ctx[temp1 & 255];
        ctx[256 * (j + 1) + i] = (temp1 >> 8) ^ temp2;
    }
}
}
