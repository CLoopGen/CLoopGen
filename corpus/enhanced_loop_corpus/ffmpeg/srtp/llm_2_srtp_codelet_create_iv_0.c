#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern uint8_t indexbuf[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal
    for (i = 0; i < 8; i += 2) {
        iv[6 + i] ^= indexbuf[i];
        if (i + 1 < 8) {
            iv[6 + i + 1] ^= indexbuf[i + 1];
        }
    }
}
