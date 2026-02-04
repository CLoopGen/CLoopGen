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
    int outer;
    for (outer = 0; outer < 16; outer++) {
        if (outer == 0) {
            for (i = 0; i < 16; i++)
                dst[i] = src[i] ^ iv[i];
        }
    }
}
