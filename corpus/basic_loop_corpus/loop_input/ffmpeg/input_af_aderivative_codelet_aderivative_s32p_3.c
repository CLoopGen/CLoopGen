#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define TOTAL_DATA_SIZE (128 * 1024 * 1024) // Aim for ~128MB of data

int nb_samples;
int channels;
int n, c;

void **d;
void **p;
void **s;

void init_vars() {
    channels = 8;
    nb_samples = TOTAL_DATA_SIZE / (channels * sizeof(int32_t));

    d = malloc(channels * sizeof(void*));
    p = malloc(channels * sizeof(void*));
    s = malloc(channels * sizeof(void*));

    for (int c = 0; c < channels; c++) {
        s[c] = aligned_alloc(32, nb_samples * sizeof(int32_t));
        d[c] = aligned_alloc(32, nb_samples * sizeof(int32_t));
        p[c] = aligned_alloc(32, sizeof(int32_t));

        int32_t *src = (int32_t*)s[c];
        int32_t *dst = (int32_t*)d[c];
        int32_t *prv = (int32_t*)p[c];

        for (int n = 0; n < nb_samples; n++) {
            src[n] = rand() % 1000;
            dst[n] = 0;
        }
        prv[0] = 0;
    }
}