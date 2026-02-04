#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; ++j) {
        for (; i < size; i += bpp) {
            unsigned int s = *(int *)(src + i);
            p = ((s & 2139062143) + (p & 2139062243)) ^ ((s ^ p) & 2155905152U);
            *(int *)(dst + i) = p;
        }
    }
}
