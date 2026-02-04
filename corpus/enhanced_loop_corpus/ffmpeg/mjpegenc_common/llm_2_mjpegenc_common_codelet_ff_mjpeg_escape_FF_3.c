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
    int acc, v;
    // Changed to consecutive 32-bit word access using pointer arithmetic
    uint32_t *buf32 = (uint32_t *)&buf[i];
    v = buf32[0];
    acc = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = buf32[1];
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = buf32[2];
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = buf32[3];
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    acc >>= 4;
    acc += (acc >> 16);
    acc += (acc >> 8);
    ff_count += acc & 255;
}
}
