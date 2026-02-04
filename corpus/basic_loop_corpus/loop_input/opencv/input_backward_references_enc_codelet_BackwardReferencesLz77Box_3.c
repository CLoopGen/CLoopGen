#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int window_offsets[32];
int window_offsets_new[32];
int window_offsets_size;
int window_offsets_new_size;

void init_vars() {
    window_offsets_size = 32;
    window_offsets_new_size = 0;

    for (int idx = 0; idx < window_offsets_size; ++idx) {
        window_offsets[idx] = (idx * 3) % 100;
        window_offsets_new[idx] = 0;
    }
}