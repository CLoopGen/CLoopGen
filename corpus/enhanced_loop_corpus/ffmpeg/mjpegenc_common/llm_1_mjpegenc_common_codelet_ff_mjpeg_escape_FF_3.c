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
        int acc1 = 0, acc2 = 0, acc3 = 0, acc4 = 0;
        int v;

        v = *(uint32_t *)(&buf[i]);
        acc1 = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
        v = *(uint32_t *)(&buf[i + 4]);
        acc2 = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
        v = *(uint32_t *)(&buf[i + 8]);
        acc3 = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
        v = *(uint32_t *)(&buf[i + 12]);
        acc4 = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;

        int acc = acc1 + acc2 + acc3 + acc4;
        acc >>= 4;
        acc += (acc >> 16);
        acc += (acc >> 8);
        ff_count += acc & 255;
    }
}
