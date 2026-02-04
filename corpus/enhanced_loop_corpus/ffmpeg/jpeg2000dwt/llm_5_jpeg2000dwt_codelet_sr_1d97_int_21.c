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
    int32_t *local_p = p;
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1) + 1;

    for (i = start; i < end; i++) {
        if ((local_p[2 * i] ^ local_p[2 * i + 2]) & 1) {
            local_p[2 * i + 1] -= (57862LL * (local_p[2 * i] + (int64_t)local_p[2 * i + 2]) + (1 << 15)) >> 16;
        } else {
            local_p[2 * i + 1] -= (int32_t)((local_p[2 * i] - local_p[2 * i + 2]) >> 1);
        }
    }
}
