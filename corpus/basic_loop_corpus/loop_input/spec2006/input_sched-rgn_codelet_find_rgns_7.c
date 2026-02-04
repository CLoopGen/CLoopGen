#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    int rgn_nr_blocks;
    int rgn_blocks;
} region;

int n_basic_blocks = 100000;
int nr_regions = 0;
region *rgn_table;
int *rgn_bb_table;
int *block_to_bb;
int *containing_rgn;
int *degree;
int i;
int idx;

void init_vars() {
    n_basic_blocks = 100000;
    nr_regions = 0;
    idx = 0;

    rgn_table = (region*)calloc(n_basic_blocks, sizeof(region));
    rgn_bb_table = (int*)malloc(n_basic_blocks * sizeof(int));
    block_to_bb = (int*)malloc(n_basic_blocks * sizeof(int));
    containing_rgn = (int*)malloc(n_basic_blocks * sizeof(int));
    degree = (int*)malloc(n_basic_blocks * sizeof(int));

    for (i = 0; i < n_basic_blocks; i++) {
        degree[i] = (i % 7 == 0) ? -1 : 1;
        block_to_bb[i] = -1;
        containing_rgn[i] = -1;
    }
}