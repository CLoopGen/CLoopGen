#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    int rgn_nr_blocks;
    int rgn_blocks;
} region;

int n_basic_blocks;
region *rgn_table;
int *rgn_bb_table;
int *block_to_bb;
int *containing_rgn;
int i;

void init_vars() {
    n_basic_blocks = 65536; // Sized to run loop in ~0.01 seconds on modern CPU

    rgn_table = (region *)calloc(n_basic_blocks, sizeof(region));
    rgn_bb_table = (int *)malloc(n_basic_blocks * sizeof(int));
    block_to_bb = (int *)malloc(n_basic_blocks * sizeof(int));
    containing_rgn = (int *)malloc(n_basic_blocks * sizeof(int));

    if (!rgn_table || !rgn_bb_table || !block_to_bb || !containing_rgn) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}