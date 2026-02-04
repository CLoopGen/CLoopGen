#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *dfs_nr;
extern int i;
extern int unreachable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i++) {
        if (dfs_nr[i] != 0) {
            continue;
        }
        unreachable = 1;
        break;
    }
}
