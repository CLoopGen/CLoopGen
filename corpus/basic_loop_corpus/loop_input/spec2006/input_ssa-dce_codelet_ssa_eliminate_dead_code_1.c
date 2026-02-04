#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int n_basic_blocks;
int i;
int *pdom;

void init_vars() {
    n_basic_blocks = 65536; // Adjust size to achieve ~0.01 sec runtime
    pdom = (int*)malloc(n_basic_blocks * sizeof(int));
    if (!pdom) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int j = 0; j < n_basic_blocks; ++j) {
        pdom[j] = (j % 7 == 0) ? -3 : j % 100; // Initialize some values to -3 to trigger the condition
    }
}