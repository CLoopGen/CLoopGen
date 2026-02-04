#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern uint8_t indexbuf[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[8];
    for (i = 0; i < 8; i++) {
        temp[i] = iv[6 + i] ^ indexbuf[i];
    }
    for (i = 0; i < 8; i++) {
        iv[6 + i] = temp[i];
    }
}
