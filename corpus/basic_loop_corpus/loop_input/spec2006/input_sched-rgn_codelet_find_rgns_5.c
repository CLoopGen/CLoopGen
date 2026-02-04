#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n_basic_blocks;
int *degree;
int i;

void init_vars() {
    n_basic_blocks = 65536; // Size chosen to make loop take ~0.01s
    degree = (int *)calloc(n_basic_blocks, sizeof(int));
    if (!degree) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}