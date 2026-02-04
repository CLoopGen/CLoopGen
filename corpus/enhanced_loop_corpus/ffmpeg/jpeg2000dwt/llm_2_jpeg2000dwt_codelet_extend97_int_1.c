#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset stride simulation
    int32_t *base0 = &p[i0];
    int32_t *base1 = &p[i1 - 1];
    for (i = 1; i <= 4; i++) {
        base0[-i] = base0[i];
        base1[i] = base1[-i - 2];
    }
}
