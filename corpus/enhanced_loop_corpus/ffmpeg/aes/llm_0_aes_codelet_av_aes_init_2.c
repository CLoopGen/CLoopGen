#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t sbox[256];
extern uint8_t inv_sbox[256];
extern int i;
extern int j;
extern uint8_t log8[256];
extern uint8_t alog8[512];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    for (int k = 0; k < 16; k++) {
        int idx = (i << 4) | k;
        j = idx ? alog8[255 - log8[idx]] : 0;
        j ^= (j << 1) ^ (j << 2) ^ (j << 3) ^ (j << 4);
        j = (j ^ (j >> 8) ^ 99) & 255;
        inv_sbox[j] = idx;
        sbox[idx] = j;
    }
}
}
