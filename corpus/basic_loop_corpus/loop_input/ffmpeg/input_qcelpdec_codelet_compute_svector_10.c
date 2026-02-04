#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_DATA_POINTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

int16_t qcelp_rate_full_codebook[128] = {0};

float *gain;
float *cdn_vector;
int i;
int j;
uint16_t cbseed;
float tmp_gain;

void init_vars() {
    gain = (float *)aligned_alloc(32, 4 * sizeof(float));
    cdn_vector = (float *)aligned_alloc(32, TOTAL_DATA_POINTS * sizeof(float));

    if (!gain || !cdn_vector) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < 4; idx++) {
        gain[idx] = 1.0f + idx * 0.25f;
    }

    for (int idx = 0; idx < 128; idx++) {
        qcelp_rate_full_codebook[idx] = (int16_t)(idx - 64);
    }

    cbseed = 37;
}