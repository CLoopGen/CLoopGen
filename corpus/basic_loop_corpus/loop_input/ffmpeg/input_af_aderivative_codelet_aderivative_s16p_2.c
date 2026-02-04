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
    nb_samples = TOTAL_DATA_SIZE / (channels * sizeof(int16_t) * 3); // s, d, p each have int16_t arrays

    d = malloc(channels * sizeof(void*));
    p = malloc(channels * sizeof(void*));
    s = malloc(channels * sizeof(void*));

    for (int c = 0; c < channels; c++) {
        s[c] = aligned_alloc(16, nb_samples * sizeof(int16_t));
        d[c] = aligned_alloc(16, nb_samples * sizeof(int16_t));
        p[c] = aligned_alloc(16, sizeof(int16_t));
        ((int16_t*)p[c])[0] = 0;

        int16_t *src = (int16_t*)s[c];
        for (int n = 0; n < nb_samples; n++) {
            src[n] = rand() % 65536 - 32768;
        }
    }
}