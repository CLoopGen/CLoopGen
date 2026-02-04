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
    int start = (i0 >> 2);
    int end = (i1 >> 2) + 2;
    for (i = start; i < end; i += 2) {
        p[4 * i] -= (3472LL * (p[4 * i - 1] + p[4 * i + 1]) + (1 << 15)) >> 16;
        p[4 * i + 2] -= (3472LL * (p[4 * i + 1] + p[4 * i + 3]) + (1 << 15)) >> 16;
    }
}
