#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define TOTAL_DATA_SIZE (128 * 1024 * 1024) // ~128 MB target

void **d;
void **p;
void **s;
int nb_samples;
int channels;
int n;
int c;

void init_vars() {
    channels = 8;
    nb_samples = TOTAL_DATA_SIZE / (channels * sizeof(float) * 3); // s, d, p each have float arrays

    s = malloc(channels * sizeof(void*));
    d = malloc(channels * sizeof(void*));
    p = malloc(channels * sizeof(void*));

    for (int c = 0; c < channels; c++) {
        s[c] = aligned_alloc(32, nb_samples * sizeof(float));
        d[c] = aligned_alloc(32, nb_samples * sizeof(float));
        p[c] = aligned_alloc(32, 1 * sizeof(float));

        float *src = (float*)s[c];
        float *dst = (float*)d[c];
        float *prv = (float*)p[c];

        for (int n = 0; n < nb_samples; n++) {
            src[n] = (float)(n + c);
            dst[n] = 0.0f;
        }
        prv[0] = 0.0f;
    }
}