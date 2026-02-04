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
    for (i = (i0 >> 2); i < (i1 >> 2) + 4; i++) {
        int64_t temp1 = p[4 * i - 2];
        int64_t temp2 = p[4 * i];
        int64_t temp3 = p[4 * i + 2];
        int64_t sum = temp1 + temp2 + temp3;
        p[4 * i] -= (35791LL * sum + (1 << 15)) >> 16;
        p[4 * i + 2] -= (35791LL * (temp2 + temp3 + p[4 * i + 4]) + (1 << 15)) >> 16;
    }
}
