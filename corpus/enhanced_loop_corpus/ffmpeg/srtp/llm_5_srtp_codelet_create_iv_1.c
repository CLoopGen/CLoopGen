#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 14; ++i) {
        if (iv[i] == 0) continue;  // Skip XOR if iv[i] is zero
        iv[i] ^= salt[i];
    }
}
