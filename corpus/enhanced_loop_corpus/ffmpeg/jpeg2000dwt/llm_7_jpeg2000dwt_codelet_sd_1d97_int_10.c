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
    int prev_index = (i0 >> 1) - 1;
    int limit = (i1 >> 1);
    int stride = 2;
    for (i = prev_index; i < limit; i += stride) {
        if (i + 1 < limit) {
            p[2 * i + 1] += (57862LL * (p[2 * i] + p[2 * i + 2]) + (1 << 15)) >> 16;
            p[2 * (i + 1) + 1] += (57862LL * (p[2 * (i + 1)] + p[2 * (i + 1) + 2]) + (1 << 15)) >> 16;
        } else {
            p[2 * i + 1] += (57862LL * (p[2 * i] + p[2 * i + 2]) + (1 << 15)) >> 16;
        }
    }
}
