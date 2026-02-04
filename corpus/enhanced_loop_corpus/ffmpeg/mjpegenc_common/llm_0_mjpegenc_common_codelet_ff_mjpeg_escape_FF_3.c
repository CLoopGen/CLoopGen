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
        for (int j = 0; j < 16; j += 4) {
            int v = *(uint32_t *)(&buf[i + j]);
            acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
        }
        acc >>= 4;
        acc += (acc >> 16);
        acc += (acc >> 8);
        ff_count += acc & 255;
    }
}
