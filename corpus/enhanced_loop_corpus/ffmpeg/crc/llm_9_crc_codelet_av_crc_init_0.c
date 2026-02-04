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
for (i = 0; i < 128; i += 2) {
    for (j = 0; j < 4; j++) {
        AVCRC index_val = ctx[256 * j + i];
        ctx[256 * (j + 1) + i] = (index_val >> 8) ^ ctx[index_val & 255];
        if (i + 1 < 128) {
            AVCRC index_val_next = ctx[256 * j + i + 1];
            ctx[256 * (j + 1) + i + 1] = (index_val_next >> 8) ^ ctx[index_val_next & 255];
        }
    }
}
}
