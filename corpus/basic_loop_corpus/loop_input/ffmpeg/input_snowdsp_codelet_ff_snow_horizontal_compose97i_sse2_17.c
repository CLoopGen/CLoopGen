#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int i;

#define DATA_SIZE (128 * 1024 * 1024)  // 128 MB total data

static IDWTELEM b_data[DATA_SIZE / sizeof(IDWTELEM)];
static IDWTELEM temp_data[DATA_SIZE / sizeof(IDWTELEM)];

void init_vars() {
    // Initialize pointers to point to aligned memory regions
    b = (IDWTELEM*)b_data;
    temp = (IDWTELEM*)temp_data;

    // Ensure array sizes are sufficient for the loop logic
    // Loop does: i -= 62; then i >= 0; i -= 64
    // Accesses b[i], b[i>>1] with offsets up to 48, and same for temp
    // So we require i_max = 62, and b[i>>1 + 48/16] => need at least (31 + 3) = 34 shorts in temp per block
    // But we're using large arrays, so just ensure alignment and bounds

    // Clear the arrays to avoid undefined behavior
    memset(b_data, 0, sizeof(b_data));
    memset(temp_data, 0, sizeof(temp_data));

    // Set i to a value that ensures loop runs meaningfully but safely
    // We want i starting from a value such that after "i -= 62", it's still >= 0
    // And we require b[i], b[i>>1], temp[i>>1] to be valid with +48 byte offsets (i.e., +24 elements)
    // Let’s choose initial i such that after subtracting 62, it's a multiple of 64 and within bounds
    // Max i after -=62 should be <= (min(sizeof_b, sizeof_temp*2)) - 24 to allow offset indexing

    size_t max_safe_index = (sizeof(b_data)/sizeof(IDWTELEM) - 64);
    max_safe_index = (max_safe_index / 64) * 64;  // round down to multiple of 64
    if (max_safe_index > 65536) max_safe_index = 65536;

    i = max_safe_index + 62;

    // Ensure temp has enough data: accessed at i>>1 with offset 48 bytes = 24 shorts
    size_t min_temp_size = (max_safe_index >> 1) + 24;
    if (min_temp_size >= sizeof(temp_data)/sizeof(IDWTELEM)) {
        // Fallback safety
        i = 62;  // smallest valid start
    }
}