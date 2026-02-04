#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int path[2800][2800];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern with Transposed Indexing
    // Access memory in a cache-friendly, consecutive manner by swapping loop order
    // to column-major traversal, which improves spatial locality for typical row-major storage
    // when multiple iterations are considered. This changes the memory access pattern
    // to be more sequential in memory.
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++) {
            path[i][j] = i * j % 7 + 1;
            if ((i + j) % 13 == 0 || (i + j) % 7 == 0 || (i + j) % 11 == 0)
                path[i][j] = 999;
        }
}
