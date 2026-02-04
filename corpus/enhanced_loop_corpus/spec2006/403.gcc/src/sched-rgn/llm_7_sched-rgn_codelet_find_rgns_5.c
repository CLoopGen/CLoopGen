#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n_basic_blocks; i++)
        degree[i] = degree[i-1] + 1;
    if (n_basic_blocks > 0)
        degree[0] = 0;
    // Introduces a RAW (read-after-write) loop-carried dependency: each iteration reads degree[i-1]
    // which was written in the previous iteration, creating sequential dependence
    // Eliminates the original independent zero-initialization pattern
}
