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
for (; i < size; i += (bpp * 2)) {
    unsigned int s1 = *(int *)(src + i);
    unsigned int s2 = (i + bpp < size) ? *(int *)(src + i + bpp) : s1;
    p = ((s1 & 2139062143) + (p & 2139062143)) ^ ((s1 ^ p) & 2155905152U);
    p = ((s2 & 2139062143) + (p & 2139062143)) ^ ((s2 ^ p) & 2155905152U);
    *(int *)(dst + i) = p;
    if (i + bpp < size) {
        *(int *)(dst + i + bpp) = p;
    }
}
}
