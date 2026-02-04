#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

static int *right_storage;
static int *p_storage;

void init_vars() {
    ni = 1 << 22; // Approximately 16 million elements, ~64 MB per array (assuming 4-byte int)

    right_storage = (int *)calloc(ni, sizeof(int));
    p_storage = (int *)malloc(ni * sizeof(int));

    if (!right_storage || !p_storage) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p_storage[j] = rand();
    }

    right = right_storage;
    p = p_storage;
}