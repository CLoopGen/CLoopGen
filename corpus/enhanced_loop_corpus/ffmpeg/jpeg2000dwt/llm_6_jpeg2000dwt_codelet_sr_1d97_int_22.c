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
    int32_t temp_load = p[2 * i - 1] + (int64_t)p[2 * i + 1];
    for (i = (i0 >> 1); i < (i1 >> 1) + 1; i++) {
        int64_t computed_val = (3472LL * temp_load + (1 << 15)) >> 16;
        p[2 * i] += computed_val;
        temp_load = p[2 * i - 1] + (int64_t)p[2 * i + 1];
    }
}
