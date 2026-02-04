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
int temp_ff_count = ff_count;
for (; i < size - 15; i += 16) {
    int acc = 0;
    uint32_t v;

    v = *(uint32_t *)(&buf[i]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 4]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 8]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 12]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;

    acc >>= 4;
    acc += (acc >> 16);
    acc += (acc >> 8);
    temp_ff_count += acc & 255;
}
ff_count = temp_ff_count;
}
