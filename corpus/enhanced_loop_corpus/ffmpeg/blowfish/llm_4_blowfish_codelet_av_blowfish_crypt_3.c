#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern uint8_t *iv;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        if (!(i & 1))  // Only process even indices
            dst[i] = src[i] ^ iv[i];
        else
            dst[i] = src[i];  // No XOR for odd indices
    }
}
