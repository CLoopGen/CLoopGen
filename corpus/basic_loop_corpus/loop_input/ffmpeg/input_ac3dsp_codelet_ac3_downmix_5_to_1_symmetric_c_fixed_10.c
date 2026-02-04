#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **samples;
int len = 65536;
int i;
int64_t v0;
int16_t front_mix = 1800;
int16_t center_mix = 1600;
int16_t surround_mix = 1400;

void init_vars() {
    samples = (int32_t**)calloc(5, sizeof(int32_t*));
    for (int j = 0; j < 5; j++) {
        samples[j] = (int32_t*)calloc(len, sizeof(int32_t));
        for (int k = 0; k < len; k++) {
            samples[j][k] = rand() % 65536 - 32768;
        }
    }
}