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
for (; i < size - 7; i += 8) {
    int acc1, acc2, v;
    // First unrolled iteration group (4 reads)
    v = *(uint32_t *)(&buf[i]);
    acc1 = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 4]);
    acc1 += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    acc1 >>= 4;
    acc1 += (acc1 >> 16);
    acc1 += (acc1 >> 8);

    // Second unrolled iteration group (4 reads), processed separately to increase instruction-level parallelism
    v = *(uint32_t *)(&buf[i + 8]);
    acc2 = (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    v = *(uint32_t *)(&buf[i + 12]);
    acc2 += (((v & (v >> 4)) & 252645135) + 16843009) & 269488144;
    acc2 >>= 4;
    acc2 += (acc2 >> 16);
    acc2 += (acc2 >> 8);

    // Aggregate results after independent computation
    ff_count += (acc1 & 255) + (acc2 & 255);
}
}
