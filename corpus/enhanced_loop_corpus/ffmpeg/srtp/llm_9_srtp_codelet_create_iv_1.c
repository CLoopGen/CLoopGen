#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 28; i++) {
        int idx = i % 14;
        iv[idx] ^= salt[idx] ^ (uint8_t)(i >> 3);
    }
}
