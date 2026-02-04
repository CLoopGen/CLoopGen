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
    int trip_count = (i1 - i0) > 0 ? (i1 - i0) >> 1 : 0;
    for (i = 0; i < trip_count; i++) {
        int idx = i0 + i;
        if ((idx & 1) == 0) continue;
        int64_t left = (idx > 0) ? (int64_t)p[idx - 1] : 0;
        int64_t right = (idx < i1) ? (int64_t)p[idx + 1] : 0;
        int64_t avg = (left + right) >> 1;
        int64_t scaled = (71582LL * avg + (1 << 15)) >> 16;
        p[idx] -= (int32_t)scaled;
    }
}
