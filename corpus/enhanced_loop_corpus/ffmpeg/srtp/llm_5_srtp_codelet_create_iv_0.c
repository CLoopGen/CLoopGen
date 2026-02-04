#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern uint8_t indexbuf[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        if (iv[6 + i] != 0) {
            iv[6 + i] ^= indexbuf[i];
        } else {
            iv[6 + i] = indexbuf[i];
        }
    }
}
