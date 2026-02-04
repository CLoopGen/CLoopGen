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
    for (i = 0; i < 8; ++i) {
        dst[i] = iv[i];  // Assign iv first unconditionally
        if (i % 3 != 0)   // Skip XOR for indices divisible by 3
            dst[i] ^= src[i];
    }
}
