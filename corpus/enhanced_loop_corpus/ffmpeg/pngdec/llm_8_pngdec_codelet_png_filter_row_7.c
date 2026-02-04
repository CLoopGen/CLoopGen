#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = bpp; j < size; j++) {
        dst[j] = ((dst[j - bpp]) + src[j]) ^ src[j - bpp];
    }
}
