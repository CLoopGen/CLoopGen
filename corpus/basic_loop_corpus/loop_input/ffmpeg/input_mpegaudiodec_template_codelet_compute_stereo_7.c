#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int *tab0;
int *tab1;
unsigned int tmp0;
unsigned int tmp1;

static int *tab0_storage;
static int *tab1_storage;

void init_vars() {
    size_t num_elements = 67108864; // ~256MB total for two arrays (each int is 4 bytes)

    tab0_storage = aligned_alloc(32, num_elements * sizeof(int));
    tab1_storage = aligned_alloc(32, num_elements * sizeof(int));

    if (!tab0_storage || !tab1_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    tab0 = tab0_storage;
    tab1 = tab1_storage;

    for (size_t idx = 0; idx < num_elements; ++idx) {
        tab0[idx] = (int)(idx % 1000);
        tab1[idx] = (int)((idx + 500) % 1000);
    }

    i = 0;
    tmp0 = 0;
    tmp1 = 0;
}