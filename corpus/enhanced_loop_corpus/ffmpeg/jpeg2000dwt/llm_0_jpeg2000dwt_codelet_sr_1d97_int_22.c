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
    for (int outer = 0; outer < 1; outer++) {
        for (i = (i0 >> 1); i < (i1 >> 1) + 1; i++)
            p[2 * i] += (3472LL * (p[2 * i - 1] + (int64_t)p[2 * i + 1]) + (1 << 15)) >> 16;
    }
}
