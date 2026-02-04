#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *vector;
int length;
int max;
int i;

void init_vars() {
    length = 65536 * 2; // ~256KB of data (65536*2*2 = 262144 bytes), suitable for ~0.01 sec runtime
    vector = aligned_alloc(32, length * sizeof(int16_t));
    if (!vector) {
        exit(1);
    }

    for (int idx = 0; idx < length; idx++) {
        vector[idx] = (int16_t)(rand() % 65536 - 32768); // Random signed 16-bit values
    }

    max = 0;
    i = 0;
}