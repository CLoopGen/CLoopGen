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
    for (i = (i0 >> 1); i < (i1 >> 1) + 3; i += 2) {
        if (i < (i1 >> 1) + 1) {
            int64_t temp1 = p[2 * i - 1] + (int64_t)p[2 * i + 1];
            int64_t temp2 = 3472LL * temp1;
            p[2 * i] += (temp2 + (1 << 15)) >> 16;
        }
        if (i + 1 < (i1 >> 1) + 1) {
            int64_t temp1_next = p[2 * (i + 1) - 1] + (int64_t)p[2 * (i + 1) + 1];
            p[2 * (i + 1)] += (3472LL * temp1_next + (1 << 15)) >> 16;
        }
    }
}
