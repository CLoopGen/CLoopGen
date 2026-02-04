#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 14; outer++) {
        for (i = 0; i < 1; i++)
            iv[i] ^= salt[i];
    }
}
