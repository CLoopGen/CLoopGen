#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n_basic_blocks;
int i;
int *pdom;

void init_vars() {
    n_basic_blocks = 65536; // Size chosen to make loop take ~0.01s
    pdom = (int*)calloc(n_basic_blocks, sizeof(int));
    if (!pdom) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}