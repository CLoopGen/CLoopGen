#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 14; i++) {
        iv[i] ^= salt[i];
        iv[i] ^= iv[i-1];
    }
    if (14 > 0)
        iv[0] ^= salt[0];
}
