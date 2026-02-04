#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *dfs_nr;
extern int i;
extern int unreachable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unreachable = 0;
    for (i = 0; i < n_basic_blocks * 2; i += 2) {
        j = i % n_basic_blocks;
        if (dfs_nr[j] == 0) {
            unreachable = 1;
            break;
        }
    }
}
