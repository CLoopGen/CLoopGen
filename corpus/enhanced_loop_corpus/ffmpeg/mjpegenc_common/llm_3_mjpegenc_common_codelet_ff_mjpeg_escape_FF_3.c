#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < size - 15; i += 16) {
    int acc = 0;
    // Strided access: process every 4th byte first, then step through lanes
    for (int stride = 0; stride < 4; stride++) {
        for (int j = 0; j < 16; j += 4) {
            int idx = i + j + stride;
            uint32_t v = *(uint32_t *)(&buf[idx]);
            acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
        }
    }
    acc >>= 4;
    acc += (acc >> 16);
    acc += (acc >> 8);
    ff_count += acc & 255;
}
}
