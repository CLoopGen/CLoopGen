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
    if (i < size) {
        for (int outer = i; outer < size; outer = (outer + bpp * 4) > size ? size : outer + bpp * 4) {
            for (int inner = outer; inner < outer + bpp * 4 && inner < size; inner += bpp) {
                unsigned int s = *(int *)(src + inner);
                p = ((s & 2139062143) + (p & 2139062143)) ^ ((s ^ p) & 2155905152U);
                *(int *)(dst + inner) = p;
            }
        }
    }
}
