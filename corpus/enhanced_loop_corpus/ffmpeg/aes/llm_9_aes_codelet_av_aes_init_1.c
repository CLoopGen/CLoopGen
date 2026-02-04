#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern uint8_t log8[256];
extern uint8_t alog8[512];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 510; i += 3) {
    int temp1 = (i % 255);
    int temp2 = (j + 1) & 255;
    alog8[temp1] = j;
    alog8[temp1 + 255] = temp2;
    log8[temp2] = temp1;
    j ^= (j << 1) ^ (j >> 1);
    if (j > 255)
        j ^= 283;
    j = (j + 1) & 511;
}
}
