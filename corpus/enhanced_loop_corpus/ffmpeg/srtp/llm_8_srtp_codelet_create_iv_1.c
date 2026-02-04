#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 14; i += 2) {
        iv[i] ^= salt[i];
        if (i + 1 < 14) {
            iv[i + 1] ^= salt[i + 1];
        }
    }
}
