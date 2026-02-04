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
    unsigned int temp = p;
    for (; i < size; i += bpp) {
        unsigned int s = *(int *)(src + i);
        temp = ((s & 2139062143) + (temp & 2139062143)) ^ ((s ^ temp) & 2155905152U);
        *(int *)(dst + i) = temp;
    }
    p = temp;
}
