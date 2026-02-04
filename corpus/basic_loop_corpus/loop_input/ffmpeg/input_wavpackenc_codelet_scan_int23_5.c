#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples_l;
int32_t *samples_r;
int nb_samples;
uint32_t magdata;
uint32_t ordata;
uint32_t xordata;
uint32_t anddata;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB total for both arrays (each int32_t is 4 bytes)

    nb_samples = data_size / sizeof(int32_t);

    samples_l = aligned_alloc(32, data_size);
    samples_r = aligned_alloc(32, data_size);

    if (!samples_l || !samples_r) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (int32_t)(j * 7 + 1);
        samples_r[j] = (int32_t)(j * 11 - 5);
    }

    magdata = 0;
    ordata = 0;
    xordata = 0xFFFFFFFF;
    anddata = 0xFFFFFFFF;
    i = 0;
}