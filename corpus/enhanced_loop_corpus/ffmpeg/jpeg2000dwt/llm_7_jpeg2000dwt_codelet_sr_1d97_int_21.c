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
if ((i0 >> 1) - 1 < (i1 >> 1) + 1) {
    int32_t prev_val = p[2 * ((i0 >> 1) - 1)];
    for (i = (i0 >> 1); i < (i1 >> 1) + 1; i++) {
        int64_t combined = (int64_t)prev_val + p[2 * i + 2];
        int32_t delta = (57862LL * combined + (1 << 15)) >> 16;
        p[2 * i + 1] -= delta;
        prev_val = p[2 * i]; 
    }
}
}
