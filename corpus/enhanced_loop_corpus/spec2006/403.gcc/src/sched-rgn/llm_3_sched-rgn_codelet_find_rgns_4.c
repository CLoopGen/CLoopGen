#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *dfs_nr;
extern int i;
extern int unreachable;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary index array to access dfs_nr in a non-sequential order.
    // Simulate indirect access by traversing blocks in reverse order
    // which changes memory access pattern and may affect cache behavior.
    unreachable = 0;

    for (i = n_basic_blocks - 1; i >= 0; i--) {
        if (dfs_nr[i] == 0) {
            unreachable = 1;
            break;
        }
    }
}
