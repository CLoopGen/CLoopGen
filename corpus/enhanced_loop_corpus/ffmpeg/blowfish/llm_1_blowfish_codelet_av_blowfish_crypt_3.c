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
    for (i = 0; i < 2; i++)
        for (int k = 0; k < 4; k++)
            dst[i * 4 + k] = src[i * 4 + k] ^ iv[i * 4 + k];
}
