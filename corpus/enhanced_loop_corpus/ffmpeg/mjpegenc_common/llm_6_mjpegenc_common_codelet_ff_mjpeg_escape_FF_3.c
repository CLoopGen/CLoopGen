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
    uint32_t v1 = *(uint32_t *)(&buf[i]);
    uint32_t v2 = *(uint32_t *)(&buf[i + 4]);
    uint32_t v3 = *(uint32_t *)(&buf[i + 8]);
    uint32_t v4 = *(uint32_t *)(&buf[i + 12]);

    acc1 = (((v1 & (v1 >> 4)) & 252645135) + 16843009) & 269488144;
    acc2 = (((v2 & (v2 >> 4)) & 252645135) + 16843009) & 269488144;
    acc3 = (((v3 & (v3 >> 4)) & 252645135) + 16843009) & 269488144;
    acc4 = (((v4 & (v4 >> 4)) & 252645135) + 16843009) & 269488144;

    int total_acc = (acc1 + acc2 + acc3 + acc4) >> 4;
    total_acc += (total_acc >> 16);
    total_acc += (total_acc >> 8);
    ff_count += total_acc & 255;
}
}
