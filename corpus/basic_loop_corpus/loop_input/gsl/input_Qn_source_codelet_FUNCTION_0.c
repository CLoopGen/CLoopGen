#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *right;
int h;
int i;

void init_vars() {
    ni = 65536; // Approximately 1MB of data for two int arrays (each ~256KB)
    h = ni / 2;

    left = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!left || !right) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}