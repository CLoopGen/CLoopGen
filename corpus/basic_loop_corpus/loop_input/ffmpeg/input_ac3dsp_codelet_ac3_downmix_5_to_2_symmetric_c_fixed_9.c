#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **samples;
int len = 0;
int i = 0;
int64_t v0 = 0;
int64_t v1 = 0;
int16_t front_mix = 1500;
int16_t center_mix = 1000;
int16_t surround_mix = 500;

void init_vars() {
    const int num_channels = 5;
    const int samples_per_channel = 262144; // ~5 * 4 * 262144 = ~5.24MB of data, sufficient for ~0.01s
    len = samples_per_channel;

    samples = (int32_t**)calloc(num_channels, sizeof(int32_t*));
    if (!samples) exit(1);

    for (int ch = 0; ch < num_channels; ch++) {
        samples[ch] = (int32_t*)calloc(samples_per_channel, sizeof(int32_t));
        if (!samples[ch]) exit(1);
        for (int n = 0; n < samples_per_channel; n++) {
            samples[ch][n] = rand() % 65536 - 32768;
        }
    }
}