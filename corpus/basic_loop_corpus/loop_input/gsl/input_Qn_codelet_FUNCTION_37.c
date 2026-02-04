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
    ni = 32 * 1024 * 1024 / sizeof(int);  // ~128 MB of data to target ~0.01 sec on modern CPUs

    right_storage = (int *)calloc(ni, sizeof(int));
    p_storage = (int *)malloc(ni * sizeof(int));

    if (!right_storage || !p_storage) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p_storage[j] = j * 2 + 1;  // Arbitrary initialization
    }

    right = right_storage;
    p = p_storage;
}