#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t flags;
extern int64_t out;
extern int64_t map[][2];
extern int from_idx;
extern int to_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= 2; stride *= 2) {
        for (int i = 0; map[i][0]; i += stride) {
            if (i + stride - 1 < 32 && map[i + stride - 1][0]) { // Bound check and simulate unrolling effect
                if (flags & map[i][from_idx])
                    out |= map[i][to_idx];
                if (stride == 2 && (flags & map[i+1][from_idx]))
                    out |= map[i+1][to_idx];
            }
        }
    }
}
