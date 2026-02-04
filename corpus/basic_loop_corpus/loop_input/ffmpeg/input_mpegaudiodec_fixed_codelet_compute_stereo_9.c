#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
static int *tab0_internal;
static int *tab1_internal;
int *tab0;
int *tab1;
unsigned int tmp0;
unsigned int tmp1;

void init_vars() {
    size_t num_elements = 67108864; // ~256MB total (two arrays of int, each ~256MB / (2 * sizeof(int)) ≈ 33.5M elements)
    
    tab0_internal = aligned_alloc(32, num_elements * sizeof(int));
    tab1_internal = aligned_alloc(32, num_elements * sizeof(int));

    if (!tab0_internal || !tab1_internal) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    tab0 = tab0_internal;
    tab1 = tab1_internal;

    for (size_t idx = 0; idx < num_elements; idx++) {
        tab0[idx] = (int)(idx % 1000);
        tab1[idx] = (int)((idx + 500) % 1000);
    }

    i = 0;
    tmp0 = 0;
    tmp1 = 0;
}