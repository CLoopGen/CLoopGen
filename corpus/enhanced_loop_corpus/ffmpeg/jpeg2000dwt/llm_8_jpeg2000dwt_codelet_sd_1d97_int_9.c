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
    for (i = i0; i < i1; i++) {
        if (i % 2 == 0) {
            p[i] -= (3472LL * (p[i - 1] + p[i + 1]) + (1 << 15)) >> 16;
        }
    }
}
