#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < 64; i += 8) {
    int j;
    for (j = 0; j < 8; j++) {
        int idx = i + j;
        dst[(idx >> 3) | ((idx << 3) & 56)] = src[idx];
    }
}
}
