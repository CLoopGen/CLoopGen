#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;
typedef unsigned short uint16;

uint32 *cp;
uint32 x;
uint32 w;
int samplesperpixel;
uint16 *wp;

static uint32 *cp_buffer;
static uint16 *wp_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of input data to target ~0.01s runtime
    size_t num_samples = data_size / sizeof(uint16);
    size_t num_pixels = num_samples / 3;

    w = (uint32)num_pixels;
    samplesperpixel = 3;

    cp_buffer = (uint32*)aligned_alloc(16, w * sizeof(uint32));
    wp_buffer = (uint16*)aligned_alloc(16, num_samples * sizeof(uint16));

    if (!cp_buffer || !wp_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_samples; ++i) {
        wp_buffer[i] = (uint16)((i * 12345 + 6789) & 0xFFFF);
    }

    cp = cp_buffer;
    wp = wp_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(cp_buffer);
    free(wp_buffer);
}