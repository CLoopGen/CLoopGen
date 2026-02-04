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
    ptrdiff_t stride = 4;
    for (i = 0, j = 0; i < 256; i += 1, j += stride) {
        int k_index = (j / stride) % keylen;
        y += state[i] + key[k_index];
        uint8_t SWAP_tmp = state[y];
        state[y] = state[(i * 7) % 256];
        state[(i * 7) % 256] = SWAP_tmp;
    }
}
