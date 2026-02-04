#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;
uint32_t l0;
uint32_t h0;
uint32_t l1;
uint32_t h1;

static uint8_t *block_data;
static uint8_t *pixels_data;

void init_vars() {
    const size_t total_data_size = 1 << 24; // 16 MB of data
    line_size = 1 << 10; // 1024 bytes per line
    h = (total_data_size / line_size) & ~1; // Ensure h is even so loop works correctly

    block_data = calloc(total_data_size, 1);
    pixels_data = calloc(total_data_size, 1);

    if (!block_data || !pixels_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    block = block_data;
    pixels = pixels_data;

    l0 = 33686018UL;
    h0 = 0;
    l1 = 0;
    h1 = 0;
}