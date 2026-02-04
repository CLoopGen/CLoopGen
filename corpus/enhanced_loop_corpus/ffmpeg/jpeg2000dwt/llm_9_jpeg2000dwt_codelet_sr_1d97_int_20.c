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
    for (i = (i0 >> 1); i < (i1 >> 1) + 1; i += 2) {
        int64_t val_prev = p[2 * i - 1];
        int64_t val_curr = p[2 * i];
        int64_t val_next = p[2 * i + 1];
        int64_t combined = (29066LL * (val_prev + val_curr + val_next) + (1 << 15)) >> 16;
        p[2 * i] -= combined;
        if (i + 1 < (i1 >> 1) + 1) {
            p[2 * (i + 1)] -= (29066LL * (val_curr + val_next + p[2 * i + 3]) + (1 << 15)) >> 16;
        }
    }
}
