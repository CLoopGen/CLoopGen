#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w;
int dx;
uint16_t *tmp_ptr;
uint16_t *src;
int x;
int imx;
int ioff;

static uint16_t *src_buffer;
static uint16_t *tmp_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~128MB of total data (adjustable)
    const size_t num_elements = data_size / sizeof(uint16_t);

    src_buffer = (uint16_t*)aligned_alloc(32, (num_elements + 16) * sizeof(uint16_t));
    tmp_buffer = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));

    if (!src_buffer || !tmp_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements + 16; i++) {
        src_buffer[i] = rand() & 0xFFFF;
    }
    memset(tmp_buffer, 0, num_elements * sizeof(uint16_t));

    w = num_elements;
    dx = 3;
    imx = 7;
    ioff = 0;

    tmp_ptr = tmp_buffer;
    src = src_buffer;
}