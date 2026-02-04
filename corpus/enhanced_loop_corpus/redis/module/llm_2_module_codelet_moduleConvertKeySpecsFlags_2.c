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
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // This variant accesses map entries in strides, reducing consecutive dependencies
    for (int i = 0; map[i][0] && map[i+1][0]; i += 2) {
        if (flags & map[i][from_idx])
            out |= map[i][to_idx];
        if (flags & map[i+1][from_idx])
            out |= map[i+1][to_idx];
    }
    // Handle remaining element if any
    if (map[0][0]) { // ensure array is not empty
        int i = 0;
        while (map[i][0]) i++;
        i--;
        if (i % 2 == 0) { // last index even => wasn't processed due to +2 stride
            if (flags & map[i][from_idx])
                out |= map[i][to_idx];
        }
    }
}
