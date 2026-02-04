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
    for (i = 0; i < bw_bytes; i++) {
        int t = src[i * 2] ^ src2[i * 2];  // Strided access with step of 2
        histogram[t]++;
    }
    src += stride;
    src2 += stride2;
}
}
