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
for (int i = 0; map[i][0] && map[i+1][0]; i += 2) { // Process two elements per iteration, effectively reducing loop depth over data
    if (flags & map[i][from_idx])
        out |= map[i][to_idx];
    if (flags & map[i+1][from_idx])
        out |= map[i+1][to_idx];
}
}
