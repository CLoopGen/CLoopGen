#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double * hprev;
size_t * ordprev;
size_t i;

static double * hprev_data;
static size_t * ordprev_data;
static size_t array_size = 134217728 / (sizeof(double) + sizeof(size_t)); // ~128MB total

void init_vars() {
    if (array_size < 5) array_size = 5;

    hprev_data = aligned_alloc(64, array_size * sizeof(double));
    ordprev_data = aligned_alloc(64, array_size * sizeof(size_t));

    hprev = hprev_data;
    ordprev = ordprev_data;

    for (size_t idx = 0; idx < array_size; idx++) {
        hprev[idx] = (double)(idx * 1.5);
        ordprev[idx] = idx * 3;
    }
}