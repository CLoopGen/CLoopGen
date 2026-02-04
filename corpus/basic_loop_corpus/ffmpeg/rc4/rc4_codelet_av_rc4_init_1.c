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
for (j = 0 , i = 0; i < 256; i++ , j++) {
    if (j == keylen)
        j = 0;
    y += state[i] + key[j];
    do {
        uint8_t SWAP_tmp = state[y];
        state[y] = state[i];
        state[i] = SWAP_tmp;
    } while (0);
}

}
