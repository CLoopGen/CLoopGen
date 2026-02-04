#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int subframe_size;
int i;
int16_t shift;
int16_t *selected_signal;

void init_vars() {
    subframe_size = 131072; // Approximately 256KB of data (131072 * 2 bytes)
    shift = 3; // Example shift value, within reasonable range for 1 << shift
    selected_signal = aligned_alloc(32, (size_t)subframe_size * sizeof(int16_t));
    if (!selected_signal) {
        exit(1);
    }
    for (int j = 0; j < subframe_size; j++) {
        selected_signal[j] = (int16_t)(j % 32768);
    }
}