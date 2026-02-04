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
    uint8_t temp;
    for (j = 0, i = 0; i < 256; i++) {
        if (j >= keylen)
            j = 0;
        y += state[i] + key[j];
        temp = state[i];
        state[i] = state[y];
        state[y] = temp;
        j++;
    }
}
