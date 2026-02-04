#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and offset adjustment
    int8_t *src = &par[b];
    int8_t *dst = &par_mapped[2 * b + 1];
    for (; b >= 0; b--) {
        dst[0] = dst[-1] = *src;
        src--;
        dst -= 2;
    }
}
