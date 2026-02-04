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
    for (i = (i0 >> 1) + 1; i < (i1 >> 1); i++) {
        int64_t sum_prev = p[2 * i - 3] + (int64_t)p[2 * i - 1];
        int64_t sum_curr = p[2 * i - 1] + (int64_t)p[2 * i + 1];
        int64_t sum_next = p[2 * i + 1] + (int64_t)p[2 * i + 3];
        p[2 * i] += (1736LL * sum_prev + 3472LL * sum_curr + 1736LL * sum_next + (1 << 15)) >> 16;
    }
}
