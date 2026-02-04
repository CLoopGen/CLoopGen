#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int window_offsets[32];
int window_offsets_size;

void init_vars() {
    i = 0;
    window_offsets_size = 0;
    for (int idx = 0; idx < 32; ++idx) {
        window_offsets[idx] = (idx % 7 == 0) ? 0 : (idx * 11);
    }
}