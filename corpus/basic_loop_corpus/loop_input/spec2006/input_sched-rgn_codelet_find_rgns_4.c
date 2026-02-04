#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n_basic_blocks = 1 << 20;
int *dfs_nr;
int i;
int unreachable;

void init_vars() {
    dfs_nr = (int*)calloc(n_basic_blocks, sizeof(int));
    if (!dfs_nr) {
        exit(1);
    }
    for (int idx = 1; idx < n_basic_blocks; idx++) {
        dfs_nr[idx] = 1;
    }
    // Leave dfs_nr[0] = 0 to trigger the condition in the loop
    i = 0;
    unreachable = 0;
}