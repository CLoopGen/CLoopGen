#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *in;
int16_t *out;
ptrdiff_t pitch;
int x;
int y;

static int32_t *in_buffer;
static int16_t *out_buffer;
static size_t total_size = 1 << 24; // ~16.7 million elements, approx 64MB for int32_t

void init_vars() {
    in_buffer = (int32_t*)calloc(total_size, sizeof(int32_t));
    out_buffer = (int16_t*)calloc(total_size, sizeof(int16_t));
    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    in = in_buffer;
    out = out_buffer;
    pitch = 8; // ensures row advance matches block width
}