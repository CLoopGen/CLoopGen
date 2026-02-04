#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern uint8_t indexbuf[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            iv[6 + j] ^= indexbuf[j];
        }
        for (int j = 4; j < 8; j++) {
            iv[6 + j] ^= indexbuf[j];
        }
    }
}
