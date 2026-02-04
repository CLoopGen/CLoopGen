#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_SAMPLES (DATA_SIZE_MB * (1 << 20) / sizeof(int32_t))

int32_t *buffer[2];
int nb_samples;
int decorr_shift;
int decorr_left_weight;
int i;

static int32_t data_pool[2][TOTAL_SAMPLES];

void init_vars() {
    nb_samples = TOTAL_SAMPLES;
    decorr_shift = 10;
    decorr_left_weight = 256;
    i = 0;

    buffer[0] = data_pool[0];
    buffer[1] = data_pool[1];

    for (int j = 0; j < nb_samples; j++) {
        buffer[0][j] = rand() % 65536 - 32768;
        buffer[1][j] = rand() % 65536 - 32768;
    }
}