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
for (; i < size && bpp > 0; i += bpp) {
    unsigned int s = *(int *)(src + i);
    if ((s & 1) == 0) {
        p = ((s & 2139062143) + (p & 2139062143)) ^ ((s ^ p) & 2155905152U);
    } else {
        p = s ^ p;
    }
    *(int *)(dst + i) = p;
}
}
