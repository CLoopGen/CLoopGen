#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *dfs_nr;
extern int i;
extern int unreachable;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern
    // Instead of accessing dfs_nr sequentially, use a stride of 2
    // and handle both even and odd indices in separate passes if needed.
    // Here we check every second element first, then the others.
    unreachable = 0;
    int stride = 2;
    int start;

    for (start = 0; start < stride; start++) {
        for (i = start; i < n_basic_blocks; i += stride) {
            if (dfs_nr[i] == 0) {
                unreachable = 1;
                return;
            }
        }
    }
}
