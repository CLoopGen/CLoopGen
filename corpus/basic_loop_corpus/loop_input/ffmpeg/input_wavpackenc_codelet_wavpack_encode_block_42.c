#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples_l;
int32_t *samples_r;
int i;
int nb_samples;
uint32_t crc;

void init_vars() {
    nb_samples = 16777216; // 64 MB of total data (each sample is 4 bytes, two arrays)

    samples_l = (int32_t*)malloc(nb_samples * sizeof(int32_t));
    samples_r = (int32_t*)malloc(nb_samples * sizeof(int32_t));

    if (!samples_l || !samples_r) {
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (int32_t)(j & 0x7FFFFF);
        samples_r[j] = (int32_t)((j + 12345) & 0x7FFFFF);
    }

    i = 0;
    crc = 0;
}