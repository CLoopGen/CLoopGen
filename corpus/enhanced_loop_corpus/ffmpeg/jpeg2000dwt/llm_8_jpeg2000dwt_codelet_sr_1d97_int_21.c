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
    int start = (i0 >> 2) - 2;
    int end = (i1 >> 2) + 2;
    for (i = start; i < end; i += 2) {
        int64_t val1 = p[4 * i];
        int64_t val2 = p[4 * i + 2];
        int64_t val3 = p[4 * i + 4];
        int64_t sum = val1 + val2 + val3;
        p[4 * i + 2] -= (32768LL * sum + (1 << 15)) >> 16;
    }
}
