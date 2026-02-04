#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t MPA_INT;

MPA_INT *window;
int i;
int j;

static MPA_INT *window_buffer;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024;
    window_buffer = (MPA_INT*)aligned_alloc(32, total_size);
    if (!window_buffer) {
        exit(1);
    }

    window = window_buffer;

    for (size_t idx = 0; idx < total_size / sizeof(MPA_INT); idx++) {
        window[idx] = (MPA_INT)(idx % 1000);
    }

    i = 0;
    j = 0;
}