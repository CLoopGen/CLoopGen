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
    // Variant 1: Strided memory access with reverse traversal and stride of 2
    for (i = 254; i >= 0; i -= 2) {
        int next_i = i + 1;
        uint8_t val1 = i ? alog8[255 - log8[i]] : 0;
        uint8_t val2 = next_i < 256 ? (next_i ? alog8[255 - log8[next_i]] : 0) : 0;

        val1 ^= (val1 << 1) ^ (val1 << 2) ^ (val1 << 3) ^ (val1 << 4);
        val1 = (val1 ^ (val1 >> 8) ^ 99) & 255;

        val2 ^= (val2 << 1) ^ (val2 << 2) ^ (val2 << 3) ^ (val2 << 4);
        val2 = (val2 ^ (val2 >> 8) ^ 99) & 255;

        inv_sbox[val1] = i;
        sbox[i] = val1;

        if (next_i < 256) {
            inv_sbox[val2] = next_i;
            sbox[next_i] = val2;
        }
    }
    // Handle any remaining element if loop didn't cover i=255 due to stride
    if (i == -1) {
        i = 255;
        j = i ? alog8[255 - log8[i]] : 0;
        j ^= (j << 1) ^ (j << 2) ^ (j << 3) ^ (j << 4);
        j = (j ^ (j >> 8) ^ 99) & 255;
        inv_sbox[j] = i;
        sbox[i] = j;
    }
}
