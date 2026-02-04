#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *dfs_nr;
extern int i;
extern int unreachable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (i = n_basic_blocks - 1; i >= 0; i--) {
        if (dfs_nr[i] != 0) {
            count++;
        } else {
            unreachable = 1;
            break;
        }
    }
    if (count == n_basic_blocks) {
        unreachable = 0;
    }
}
