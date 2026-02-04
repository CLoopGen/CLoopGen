#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint8_t ff_ac3_log_add_tab[260] = {0}; // Initialized to zero; legal for const array

static int16_t *psd_data;
int16_t *psd;
int bin;
int v;
int band_end;

void init_vars() {
    size_t data_size = 16 * 1024 * 1024; // ~16MB of int16_t data
    psd_data = (int16_t *)calloc(data_size, sizeof(int16_t));
    if (!psd_data) {
        exit(1);
    }

    psd = psd_data;
    bin = 0;
    v = 0;
    band_end = data_size - 1; // Ensures psd[bin] access is valid for all iterations

    for (size_t i = 0; i < data_size; i++) {
        psd[i] = rand() & 0x7FFF; // Positive values in range [0, 32767]
    }

    for (int i = 0; i < 260; i++) {
        ((uint8_t *)ff_ac3_log_add_tab)[i] = i < 260 ? (i % 256) : 0;
    }
}