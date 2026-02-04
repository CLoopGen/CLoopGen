#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h = 10000;
int i;

static uint8_t src1_buffer[256 * 1024 * 1024 + 12]; // Large buffer to cover all src1 accesses with safety margin
static int16_t tmp_buffer[256 * 1024 * 1024 / 8 * 8]; // Roughly matching output size

void init_vars() {
    srcStride = 8;

    // Ensure src1 has valid range: we access from -2 to 10 relative, so need padding at start and end
    src1 = src1_buffer + 2; // Make index 0 point to +2 so we can access -2 safely

    // Fill source data with non-zero values for meaningful computation
    for (size_t j = 0; j < sizeof(src1_buffer); ++j) {
        src1_buffer[j] = (uint8_t)(j % 251);
    }

    tmp = tmp_buffer;

    // Initialize tmp buffer to zero
    memset(tmp_buffer, 0, sizeof(tmp_buffer));
}