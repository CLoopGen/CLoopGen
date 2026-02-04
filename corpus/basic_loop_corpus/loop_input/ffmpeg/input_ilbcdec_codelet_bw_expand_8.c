#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int length;
int i;

int16_t *out;
int16_t *in;
int16_t *coef;

void init_vars() {
    length = 8000000; // Approximately 15.6 MB of data per array, total ~47 MB

    in = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));
    coef = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));

    for (int idx = 0; idx < length; idx++) {
        in[idx] = (int16_t)(rand() % 65536 - 32768);
        coef[idx] = (int16_t)(rand() % 65536 - 32768);
    }

    i = 0;
}