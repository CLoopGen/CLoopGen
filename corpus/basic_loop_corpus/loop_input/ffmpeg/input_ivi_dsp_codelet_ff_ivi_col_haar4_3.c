#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int32_t *in;
int16_t *out;
ptrdiff_t pitch;
uint8_t *flags;
int i;
int t0;
int t1;
int t2;
int t3;
int t4;

static int32_t *in_buffer;
static int16_t *out_buffer;
static uint8_t *flags_buffer;

void init_vars() {
    size_t data_size = 1 << 20; // ~4MB of input (each in element is 4 bytes)
    size_t num_elements = data_size / sizeof(int32_t);
    size_t num_iters = num_elements > 4 ? num_elements - 4 + 1 : 1; // ensure no out-of-bounds access

    in_buffer = aligned_alloc(32, num_elements * sizeof(int32_t));
    out_buffer = aligned_alloc(32, num_elements * sizeof(int16_t) * 4); // 4 outputs per iteration
    flags_buffer = aligned_alloc(32, num_iters * sizeof(uint8_t));

    for (size_t j = 0; j < num_elements; j++) {
        in_buffer[j] = rand() % 1000;
    }
    for (size_t j = 0; j < num_elements * 4; j++) {
        out_buffer[j] = 0;
    }
    for (size_t j = 0; j < num_iters; j++) {
        flags_buffer[j] = rand() & 1;
    }

    in = in_buffer;
    out = out_buffer;
    pitch = 1;
    flags = flags_buffer;
    i = 0;
    t0 = t1 = t2 = t3 = t4 = 0;
}