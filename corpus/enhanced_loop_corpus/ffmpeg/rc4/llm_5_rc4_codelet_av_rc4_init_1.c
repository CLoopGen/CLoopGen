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
    j = 0;
    for (i = 0; i < 256; i++) {
        if (j >= keylen) {
            j = 0;
        }
        y += state[i] + key[j];
        if ((y & 1) == 0) {
            uint8_t SWAP_tmp = state[y];
            state[y] = state[i];
            state[i] = SWAP_tmp;
        } else {
            uint8_t SWAP_tmp = state[(y + 1) % 256];
            state[(y + 1) % 256] = state[i];
            state[i] = SWAP_tmp;
        }
        j++;
    }
}
