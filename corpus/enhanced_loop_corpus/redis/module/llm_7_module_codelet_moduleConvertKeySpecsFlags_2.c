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
    int prev_idx = 0;
    for (int i = 0; map[i][0]; i++) {
        if (i > 0 && (flags & map[prev_idx][from_idx]))
            out |= map[i][to_idx];
        prev_idx = i;
    }
}
