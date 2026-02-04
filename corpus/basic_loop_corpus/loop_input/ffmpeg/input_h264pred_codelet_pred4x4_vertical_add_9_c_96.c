#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride = 16;

int i;

uint16_t *pix;
int32_t *block;

static uint16_t pix_data[256 * 1024 * 1024 / sizeof(uint16_t)]; // ~256MB for pix
static int32_t block_data[16 * 4]; // enough for 4 iterations with 16 elements each

void init_vars() {
    // Initialize pointers to point into the static arrays
    pix = pix_data;
    block = block_data;

    // Ensure no out-of-bounds access: loop runs 4 times, accesses block[0], [4], [8], [12] each time
    // So we need at least 16 elements in block (4 iterations * 4 offsets)
    // Each iteration increments block by 1 -> total 4 increments -> need 16 elements starting from initial block

    // Initialize all data to non-zero to avoid undefined behavior and make it easier to test
    for (size_t idx = 0; idx < sizeof(pix_data) / sizeof(pix_data[0]); idx++) {
        pix_data[idx] = (uint16_t)(idx & 0xFFFF);
    }

    for (size_t idx = 0; idx < sizeof(block_data) / sizeof(block_data[0]); idx++) {
        block_data[idx] = (int32_t)(idx + 1);
    }

    // Set stride to a reasonable value to allow strided access without going out of bounds
    // Maximum offset: 4 * stride, and we do this for 4 consecutive pix positions
    // So we require: base + 4*stride < array_size
    // We allocated large pix_data; using stride=16 is safe
    stride = 16;
}