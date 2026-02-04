#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *src2;
extern int stride2;
extern int bh;
extern int i;
extern int j;
extern uint16_t histogram[256];
extern int bw_bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bh; j++) {
    i = 0;
    for (; i < bw_bytes; ) {
        int t = src[i] ^ src2[i];
        histogram[t]++;
        i++;
        if (i % 4 == 0 && src[i-1] == 0) {
            continue;
        }
    }
    src += stride;
    src2 += stride2;
}
}
