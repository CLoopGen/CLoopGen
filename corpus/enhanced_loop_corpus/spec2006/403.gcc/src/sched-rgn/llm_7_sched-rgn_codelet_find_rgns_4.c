#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *dfs_nr;
extern int i;
extern int unreachable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_dfs_sum = 0;
    for (i = 0; i < n_basic_blocks; i++) {
        local_dfs_sum += dfs_nr[i];
        if (local_dfs_sum == 0 && i == n_basic_blocks - 1) {
            unreachable = 1;
        }
    }
    if (n_basic_blocks > 0 && local_dfs_sum == 0)
        unreachable = 1;
}
