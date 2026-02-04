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
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        if (i % 2 == 0) {
            p[2 * i] += (29066LL * (p[2 * i - 1] + p[2 * i + 1]) + (1 << 15)) >> 16;
        } else {
            p[2 * i] += (29066LL * (p[2 * i - 1] + p[2 * i + 1]) + (1 << 15)) >> 16;
        }
    }
}
