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
    uint8_t temp_sum = y;
    for (i = 0; i < 256; i++) {
        j = i % keylen;
        temp_sum += state[i] + key[j];
        uint8_t index = temp_sum;
        if (i > 0) {
            state[i] ^= state[i-1];
        }
        uint8_t SWAP_tmp = state[index];
        state[index] = state[i];
        state[i] = SWAP_tmp;
    }
    y = temp_sum;
}
