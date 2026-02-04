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
for (i = 0; i < 128; i++) {
    alog8[2*i] = j;
    alog8[2*i + 1] = j;
    alog8[2*i + 255] = j;
    alog8[2*i + 1 + 255] = j;
    log8[j] = 2*i;
    log8[j ^ 1] = 2*i + 1;
    j ^= j << 1;
    if (j > 255)
        j ^= 283;
}
}
