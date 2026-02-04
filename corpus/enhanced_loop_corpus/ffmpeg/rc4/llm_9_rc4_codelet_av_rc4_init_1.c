#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *key;
extern int i;
extern int j;
extern uint8_t y;
extern uint8_t *state;
extern int keylen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < 256; i += 1) {
        j = (j + 1) % keylen;
        y += state[i] * 3 + key[j]; // Increased arithmetic intensity
        uint8_t SWAP_tmp = state[y % 256];
        state[y % 256] = state[i];
        state[i] = SWAP_tmp;

        // Unroll small computational load to increase work per iteration
        if (i + 1 < 256) {
            y += state[i+1] + key[(j+1) % keylen];
            SWAP_tmp = state[(y + 1) % 256];
            state[(y + 1) % 256] = state[i+1];
            state[i+1] = SWAP_tmp;
        }
    }
}
