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
    int32_t temp;
    for (i = (i0 >> 1) - 1; i < (i1 >> 1) + 2; i++) {
        temp = p[2 * i - 1] + p[2 * i + 1];
        p[2 * i] -= (29066LL * temp + (1 << 15)) >> 16;
    }
}
