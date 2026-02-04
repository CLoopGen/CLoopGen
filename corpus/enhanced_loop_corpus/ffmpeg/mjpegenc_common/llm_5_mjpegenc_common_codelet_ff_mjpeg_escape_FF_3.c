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
for (; i < size - 15 && buf != NULL; i += 16) {
    int acc = 0, v;
    if (i + 12 >= size) break;
    v = *(uint32_t *)(&buf[i]);
    acc = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 4]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 8]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 12]);
    acc += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    acc >>= 4;
    acc += (acc >> 16);
    acc += (acc >> 8);
    uint8_t contribution = acc & 255;
    if (contribution != 0) ff_count += contribution;
    else continue;
}
}
