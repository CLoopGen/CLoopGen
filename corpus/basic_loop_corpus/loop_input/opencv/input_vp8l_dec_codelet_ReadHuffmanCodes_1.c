#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int num_htree_groups_max;
int huffman_pixs;

void init_vars() {
    huffman_pixs = 10000000;  // Adjust to target ~0.01 sec runtime
    num_htree_groups_max = 50;
}

void loop();