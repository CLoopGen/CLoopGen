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
int row2;
int row4;
int row8;
int t0;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
int t7;
int t8;

void init_vars() {
    const int num_iterations = 8;
    const int total_elements = 64; // Enough to allow in[56] access with 8 iterations stepping by 1
    const size_t input_size = sizeof(int32_t) * total_elements * 16384; // ~1MB of data, scale as needed
    const size_t output_size = sizeof(int16_t) * 8 * 16384;
    const size_t flags_size = sizeof(uint8_t) * num_iterations * 16384;

    int32_t *in_base = (int32_t*)calloc(total_elements, sizeof(int32_t));
    int16_t *out_base = (int16_t*)calloc(8, sizeof(int16_t));
    uint8_t *flags_base = (uint8_t*)malloc(num_iterations * sizeof(uint8_t));

    if (!in_base || !out_base || !flags_base) {
        exit(1);
    }

    // Initialize data pattern for meaningful computation
    for (size_t idx = 0; idx < total_elements; idx++) {
        in_base[idx] = (int32_t)(idx * 7919 % 1000); // Prime multiplier for pseudo-randomness
    }

    // Set pitch and derived offsets (row2 = 2*pitch, row4 = 4*pitch, row8 = 8*pitch)
    pitch = 8;
    row2 = 2 * pitch;
    row4 = 4 * pitch;
    row8 = 8 * pitch;

    // Initialize flags: alternate true/false across iterations
    for (int idx = 0; idx < num_iterations; idx++) {
        flags_base[idx] = (idx % 2 == 0) ? 1 : 0;
    }

    // Replicate data blocks to simulate larger dataset (~1-2 seconds worth)
    int32_t *expanded_in = (int32_t*)malloc(input_size);
    int16_t *expanded_out = (int16_t*)malloc(output_size);
    uint8_t *expanded_flags = (uint8_t*)malloc(flags_size);

    for (int rep = 0; rep < 16384; rep++) {
        memcpy(&expanded_in[rep * total_elements], in_base, sizeof(int32_t) * total_elements);
        memcpy(&expanded_out[rep * 8], out_base, sizeof(int16_t) * 8);
    }
    for (int rep = 0; rep < 16384; rep++) {
        memcpy(&expanded_flags[rep * num_iterations], flags_base, sizeof(uint8_t) * num_iterations);
    }

    in = expanded_in;
    out = expanded_out;
    flags = expanded_flags;

    // Reset working variables
    t0 = t1 = t2 = t3 = t4 = t5 = t6 = t7 = t8 = 0;
}