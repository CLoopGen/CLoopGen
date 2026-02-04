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
    for (i = 0; i < 2; i++) {
        int offset = i * 4;
        for (int j = 0; j < 4; j++) {
            dst[offset + j] = src[offset + j] ^ iv[offset + j];
        }
    }
}
