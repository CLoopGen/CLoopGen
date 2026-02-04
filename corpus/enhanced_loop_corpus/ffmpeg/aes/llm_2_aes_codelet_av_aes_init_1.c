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
for (i = 0; i < 255; i++) {
    int idx1 = i;
    int idx2 = i + 255;
    alog8[idx1] = alog8[idx2] = j;
    log8[j] = i;
    j ^= j + j;
    if (j > 255)
        j ^= 283;
}
}
