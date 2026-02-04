#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int num_htree_groups;
int huffman_pixs;

static int group_storage[262144];
int *const mapped_group = &group_storage[0];

void init_vars() {
    i = 0;
    num_htree_groups = 0;
    huffman_pixs = 262144;

    for (int idx = 0; idx < huffman_pixs; ++idx) {
        group_storage[idx] = -1;
    }
}