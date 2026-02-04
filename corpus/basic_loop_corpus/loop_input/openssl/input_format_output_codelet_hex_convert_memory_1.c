#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *m;
size_t n;
char *b;
size_t width;
size_t i;

static unsigned char m_data[131072]; // 128KB input data
static char b_data[393216]; // Large enough to hold hex output with spaces: each byte becomes 2 hex chars, plus space every 'width' bytes

void init_vars() {
    n = sizeof(m_data);
    width = 16;
    m = m_data;
    b = b_data;

    // Initialize m_data with known pattern (e.g., sequential values)
    for (size_t idx = 0; idx < n; ++idx) {
        m_data[idx] = (unsigned char)(idx % 256);
    }

    // Ensure b has enough space: 2 chars per byte + spaces
    // One space per 'width' group, except after last group
    size_t max_output_size = 2 * n + (n / width);
    if (sizeof(b_data) < max_output_size) {
        fprintf(stderr, "b_data buffer too small\n");
        exit(1);
    }
}