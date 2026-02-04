#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = (i0 >> 1); i < (i1 >> 1) + 1; i++) {
        temp = (3472LL * (p[2 * i - 2] + p[2 * i]) + (1 << 15)) >> 16;
        p[2 * i - 2] -= temp;
    }
}
